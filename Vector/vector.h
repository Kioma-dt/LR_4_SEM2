#pragma once
#include <memory>
#include <stdexcept>

template <typename T>
class Vector{
    private:
        T *data;
        size_t capacity_;
        size_t size_;
        std::allocator<T> allocator;

        void reallocate(size_t new_capacity);

    public:
        Vector() : data(nullptr), size_(0), capacity_(0) {};

        size_t size() const;
        size_t capacity() const;

        void push_back(const T& value);
        void pop_back();

        bool empty() const;
        void clear();

        T& at(size_t pos);
        const T& at(size_t pos) const;
        T& operator[](size_t pos);
        const T& operator[](size_t pos) const;
};