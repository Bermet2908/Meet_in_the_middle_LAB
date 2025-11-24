#pragma once

#include <cstddef>

class IntDynamicArray {
private:
    int* data_;
    std::size_t size_;
    std::size_t capacity_;

    void grow();
public:
    IntDynamicArray();
    ~IntDynamicArray();

    IntDynamicArray(const IntDynamicArray& other);
    IntDynamicArray& operator=(const IntDynamicArray& other);

    void push_back(int value);
    std::size_t size() const;
    int at(std::size_t index) const;
};

