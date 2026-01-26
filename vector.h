#pragma once
#include <stdexcept>
#include <utility>

namespace mvec
{
    template <typename T>
    class vector
    {
        T* data {nullptr};
        int numElements{};   // how many items are in array
        int capacity_{};     // how much array can store

        void resize()
        {
            const int newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;

            T* temp = new T[newCapacity];

            for (int i{}; i < numElements; i++)
                temp[i] = std::move(data[i]);

            delete[] data;
            data = temp;
            capacity_ = newCapacity;
        }

    public:

        vector()
        {
            numElements = 0;
            capacity_ = 1;
            data = new T[capacity_];
        }

        ~vector()
        {
            delete[] data;
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

            T* temp = new T[numElements];

            for (int i{}; i < numElements; i++)
                temp[i] = std::move(data[i]);

            delete[] data;
            data = temp;
            capacity_ = numElements;
        }

        void reserve(const int newCapacity)
        {
            if (newCapacity <= capacity_)
                // throw std::invalid_argument("newCapacity too small");
                return;

            T* temp = new T[newCapacity];

            for (int i{}; i < numElements; i++)
                temp[i] = std::move(data[i]);

            delete[] data;
            data = temp;
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