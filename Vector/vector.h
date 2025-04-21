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
        explicit Vector(size_t size);
        explicit Vector(size_t size, const T &value);
        Vector(const Vector &other);
        Vector(Vector &&other) noexcept;
        ~Vector();

        Vector& operator=(const Vector &other);
        Vector& operator=(Vector &&other) noexcept;

        void assign(size_t count, const T &value);

        T& at(size_t pos);
        const T& at(size_t pos) const;
        T& operator[](size_t pos);
        const T& operator[](size_t pos) const;
        T &front();
        const T &front() const;
        T &back();
        const T &back() const;
        T *getData();
        const T *data_ptr() const;

        bool empty() const;
        size_t size() const;
        size_t max_size() const;
        void reserve(size_t new_cap);
        size_t capacity() const;

        void push_back(const T& value);
        void pop_back();

        void clear();
        void resize(size_t count);
        void resize(size_t count, const T& value);
        void swap(Vector &other);
};