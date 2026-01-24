//
// Created by bartek on 1/24/26.
//

#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H

namespace myTools
{
    template <typename T>
    class vector
    {
        T* data {nullptr};
        int numElements{};  // how many items are in array
        int capacity_{};     // how much array can store

        void resize()
        {
            const int newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;

            T* temp = new T[newCapacity];

            for (int i{}; i < numElements; i++)
            {
                temp[i] = data[i];
            }
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
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity_ = numElements;
        }

        void resize(const int newCapacity)
        {
            T* temp = new T[newCapacity];

            const int elementsToCopy = (numElements < newCapacity) ? numElements : newCapacity;

            for (int i{}; i < elementsToCopy; i++)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity_ = newCapacity;

            if (numElements > newCapacity)
                numElements = newCapacity;
        }

        // ------------------------------------------------------
        // const functions

        int size() const
        {
            return numElements;
        }

        int capacity() const
        {
            return capacity_;
        }

        T& at(const int index) const
        {
            if (index < 0 || index >= numElements)
                throw std::out_of_range("Index out of range");

            return data[index];
        }
        T& at(const int index)
        {
            if (index < 0 || index >= numElements)
                throw std::out_of_range("Index out of range");

            return data[index];
        }

        T& at_perf(const int index) const
        {
            return data[index];
        }
        T& at_perf(const int index)
        {
            return data[index];
        }
    };
} // myTools

#endif //UNTITLED_VECTOR_H