# MyVector

A simple custom implementation of a dynamic array (`vector`) in C++.

## Features

- Dynamic resizing (`push_back`)
- Element removal (`pop_back`)
- Shrink to fit (`shrink_to_fit`)
- Direct access (`at` and `at_perf`)
- Manual resize support
- Exception handling for out-of-range access

## Usage

```cpp
#include "vector.h"
#include <iostream>

int main()
{
    myTools::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "Size: " << v.size() << std::endl;
    std::cout << "Capacity: " << v.capacity() << std::endl;

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << " ";
    }

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
