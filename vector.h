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
        int numElements{};   // how many items are in array
        int capacity_{};     // how much array can store

        void resize()
        {
            const int newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;

            std::unique_ptr<T[]> temp = std::make_unique<T[]>(newCapacity);

            for (int i{}; i < numElements; i++)
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

            std::unique_ptr<T[]> temp = std::make_unique<T[]>(numElements);

            for (int i{}; i < numElements; i++)
                temp[i] = std::move(data[i]);

            data = std::move(temp);
            capacity_ = numElements;
        }

        void reserve(const int newCapacity)
        {
            if (newCapacity <= capacity_)
                // throw std::invalid_argument("newCapacity too small");
                return;

            std::unique_ptr<T[]> temp = std::make_unique<T[]>(newCapacity);

            for (int i{}; i < numElements; i++)
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
        int size() const
        {
            return numElements;
        }

        int capacity() const
        {
            return capacity_;
        }

        T& at(const int index)
        {
            if (index < 0 || index >= numElements)
                throw std::out_of_range("Index out of range");

            return data[index];
        }

        T& operator[](const int index)
        {
            return data[index];
        }

        T* begin()
        {
            return data;
        }

        T* end()
        {
            return data + numElements;
        }


        // const -----------
        const T& at(const int index) const
        {
            if (index < 0 || index >= numElements)
                throw std::out_of_range("Index out of range");

            return data[index];
        }

        const T& operator[](const int index) const
        {
            return data[index];
        }

        const T* begin() const
        {
            return data;
        }

        const T* end() const
        {
            return data + numElements;
        }
    };
} // mvec
