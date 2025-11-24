#include "dynamic_array.hpp"
#include <stdexcept>

IntDynamicArray::IntDynamicArray() : data_(nullptr), size_(0), capacity_(0) {}

IntDynamicArray::~IntDynamicArray() {
    delete[] data_;
}

IntDynamicArray::IntDynamicArray(const IntDynamicArray& other) : data_(nullptr), size_(other.size_), capacity_(other.capacity_)
{
    if (capacity_ > 0) {
        data_ = new int[capacity_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

IntDynamicArray& IntDynamicArray::operator=(const IntDynamicArray& other) {
    if (this == &other) {
        return *this;
    }

    delete[] data_;

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = nullptr;

    if (capacity_ > 0) {
        data_ = new int[capacity_];
        for (std::size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    return *this;
}

void IntDynamicArray::grow() {
    std::size_t new_capacity = (capacity_ == 0) ? 4 : capacity_ * 2;
    int* new_data = new int[new_capacity];

    for (std::size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

void IntDynamicArray::push_back(int value) {
    if (size_ == capacity_) {
        grow();
    }
    data_[size_] = value;
    ++size_;
}

std::size_t IntDynamicArray::size() const {
    return size_;
}

int IntDynamicArray::at(std::size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}
