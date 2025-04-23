#ifndef VECTOR_H
#define VECTOR_H
#include <memory>
#include <stdexcept>
#include "iterator.h"

template <typename T>
class Vector {

   private:
    T* data;
    size_t capacity_;
    size_t size_;
    std::allocator<T> allocator;

    void reallocate(size_t new_capacity);

   public:
    using value_type = T;
    using allocator_type = std::allocator<T>;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_pointer = const T*;
    using iterator = Iterator<T>;
    using const_iterator = ConstIterator<T>;
    using reverse_iterator = ReverseIterator<T>;
    using const_reverse_iterator = ConstReverseIterator<T>;

    Vector() : data(nullptr), size_(0), capacity_(0) {};
    explicit Vector(size_t size);
    explicit Vector(size_t size, const T& value);
    template <typename InputIt,
              typename = std::enable_if_t<!std::is_integral_v<InputIt>>>
    Vector(InputIt first, InputIt last);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    // ~Vector();

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;

    void assign(size_t count, const T& value);
    template <typename InputIt,
              typename = std::enable_if_t<!std::is_integral_v<InputIt>>>
    void assign(InputIt first, InputIt last);

    T& at(size_t pos);
    const T& at(size_t pos) const;
    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    T* data_ptr();
    const T* data_ptr() const;

    Vector<T>::iterator begin();
    Vector<T>::iterator end();
    Vector<T>::const_iterator cbegin() const;
    Vector<T>::const_iterator cend() const;
    Vector<T>::reverse_iterator rbegin();
    Vector<T>::reverse_iterator rend();
    Vector<T>::const_reverse_iterator rcbegin() const;
    Vector<T>::const_reverse_iterator rcend() const;

    bool empty() const;
    size_t size() const;
    size_t max_size() const;
    void reserve(size_t new_cap);
    size_t capacity() const;

    void push_back(const T& value);
    void pop_back();

    void clear();

    Vector<T>::iterator insert(Vector<T>::iterator pos, const T& value);
    Vector<T>::iterator insert(Vector<T>::iterator pos, T&& value);
    Vector<T>::iterator insert(Vector<T>::iterator pos, size_t count,
                               const T& value);
    template <typename InputIt,
              typename = std::enable_if_t<!std::is_integral_v<InputIt>>>
    Vector<T>::iterator insert(Vector<T>::iterator pos, InputIt first,
                               InputIt last);

    template <typename... Args>
    Vector<T>::iterator emplace(Vector<T>::iterator pos, Args&&... args);
    template <typename... Args>
    T& emplace_back(Args&&... args);

    Vector<T>::iterator erase(Vector<T>::iterator pos);
    Vector<T>::iterator erase(Vector<T>::iterator first,
                              Vector<T>::iterator last);

    void resize(size_t count);
    void resize(size_t count, const T& value);
    void swap(Vector& other);
};
#endif
