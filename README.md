# MyVector

A simple custom implementation of a dynamic array (`vector`) in C++.

## Features

- Dynamic resizing (`push_back`)
- Element removal (`pop_back`)
- Shrink to fit (`shrink_to_fit`)
- Direct access (`at` and `at_perf`)
- Iterators (begin() and end())
- Clear all elements (clear())
- Manual resize support
- Exception handling for out-of-range access

## at() vs at_perf()

**at(index)**
- Performs bounds checking
- Throws `std::out_of_range` if the index is out of range
- Safer but slightly slower
- Intended for safe element access

**at_perf(index)**
- Does not perform bounds checking
- Faster direct access
- Undefined behavior if the index is out of range
- Intended for performance-critical code

## Usage

```cpp
#include "vector.h"
#include <iostream>

int main()
{
    mvec::vector<int> v;

    // Reserve capacity for 1000 elements
    v.reserve(1000);
    
    for (int i{};i<1000;i++)
        v.push_back(i);

    // Clear elements, but memory still allocated
    v.clear();

    // Reduce capacity to match size (0)
    v.shrink_to_fit();

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "Size: " << v.size() << std::endl;
    std::cout << "Capacity: " << v.capacity() << std::endl;

    for (const auto& i : v) {
        std::cout << i << " ";
    }

    // Remove last element
    v.pop_back();

    std::cout << "\nAfter pop_back, size: " << v.size() << std::endl;

    return 0;
}
```
## Installation
### 1. Clone the repository:
```bash
git clone https://github.com/dixe1/custom-vector
```
### 2. Include vector.h in your C++ project.
