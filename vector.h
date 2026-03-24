#pragma once
#include <memory>
#include <stdexcept>
#include <utility>

// This vector works for simple types (int, string).
// It does not support thread or mutex.

namespace mvec
{
    template <typename T>
    class vector
    {
        std::unique_ptr<T[]> data;
        size_t numElements{};   // how many items are in array
        size_t capacity_{};     // how much array can store

        void resize()
        {
            const size_t newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;

            auto temp = std::make_unique<T[]>(newCapacity);

            for (size_t i{}; i < numElements; i++)
                temp[i] = std::move(data[i]);

            data = std::move(temp);
            capacity_ = newCapacity;
        }

    public:

        vector()
        {
            numElements = 0;
            capacity_ = 1;
            data = std::make_unique<T[]>(capacity_);
        }

        // ==================================================================
        //  modify

        void push_back(const T& item)
        {
            if (numElements == capacity_)
                resize();

            data[numElements] = item;
            numElements++;
        }

        void pop_back()
        {
            if (numElements == 0)
                return;
            numElements--;
        }

        void shrink_to_fit()
        {
            if (numElements == 0)
                return;

            auto temp = std::make_unique<T[]>(numElements);

            for (size_t i{}; i < numElements; i++)
                temp[i] = std::move(data[i]);

            data = std::move(temp);
            capacity_ = numElements;
        }

        void reserve(const size_t newCapacity)
        {
            if (newCapacity <= capacity_)
                // throw std::invalid_argument("newCapacity too small");
                return;

            auto temp = std::make_unique<T[]>(newCapacity);

            for (size_t i{}; i < numElements; i++)
                temp[i] = std::move(data[i]);

            data = std::move(temp);
            capacity_ = newCapacity;
        }

        void clear()
        {
            numElements = 0;
        }

        // ========================================================================
        // info


        // normal -----------
        size_t size() const
        {
            return numElements;
        }

        size_t capacity() const
        {
            return capacity_;
        }

        T& at(const size_t index)
        {
            if (index < 0 || index >= numElements)
                throw std::out_of_range("Index out of range");

            return data[index];
        }

        T& operator[](const size_t index)
        {
            return data[index];
        }

        T* begin()
        {
            return data.get();
        }

        T* end()
        {
            return data.get() + numElements;
        }


        // const -----------
        const T& at(const size_t index) const
        {
            if (index < 0 || index >= numElements)
                throw std::out_of_range("Index out of range");

            return data[index];
        }

        const T& operator[](const size_t index) const
        {
            return data[index];
        }

        const T* begin() const
        {
            return data.get();
        }

        const T* end() const
        {
            return data.get() + numElements;
        }
    };
} // mvec
