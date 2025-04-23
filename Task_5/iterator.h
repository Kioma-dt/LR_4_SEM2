#ifndef ITERATOR_H
#define ITERATOR_H
#include <iterator>

template <typename T>
class Iterator {
   protected:
    T* ptr;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::random_access_iterator_tag;

    Iterator() : ptr(nullptr) {};
    explicit Iterator(T* pointer) : ptr(pointer) {};
    Iterator(const Iterator& other) : ptr(other.ptr) {};

    Iterator<T>::reference operator*() const;
    Iterator<T>::pointer operator->() const;

    Iterator operator+(Iterator<T>::difference_type n) const;
    Iterator operator-(Iterator<T>::difference_type n) const;
    Iterator<T>::difference_type operator-(const Iterator& other) const;

    Iterator<T>::reference operator[](Iterator<T>::difference_type n) const;

    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);

    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
    bool operator>(const Iterator& other) const;
    bool operator<(const Iterator& other) const;
    bool operator>=(const Iterator& other) const;
    bool operator<=(const Iterator& other) const;
};

template <typename T>
class ConstIterator : public Iterator<const T> {
   public:
    ConstIterator() : Iterator<const T>() {};
    ConstIterator(const T* pointer) : Iterator<const T>(pointer) {};
    ConstIterator(const ConstIterator& other) : Iterator<const T>(other) {};
};

template <typename T>
class ReverseIterator {
   protected:
    T* ptr;

   public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;
    using iterator_category = std::random_access_iterator_tag;

    ReverseIterator() : ptr(nullptr) {};
    explicit ReverseIterator(T* pointer) : ptr(pointer) {};
    ReverseIterator(const ReverseIterator& other) : ptr(other.ptr) {};

    ReverseIterator<T>::reference operator*() const;
    ReverseIterator<T>::pointer operator->() const;

    ReverseIterator operator+(ReverseIterator<T>::difference_type n) const;
    ReverseIterator operator-(ReverseIterator<T>::difference_type n) const;
    ReverseIterator<T>::difference_type operator-(
        const ReverseIterator& other) const;

    ReverseIterator<T>::reference operator[](
        ReverseIterator<T>::difference_type n) const;

    ReverseIterator& operator++();
    ReverseIterator operator++(int);
    ReverseIterator& operator--();
    ReverseIterator operator--(int);

    bool operator==(const ReverseIterator& other) const;
    bool operator!=(const ReverseIterator& other) const;
    bool operator>(const ReverseIterator& other) const;
    bool operator<(const ReverseIterator& other) const;
    bool operator>=(const ReverseIterator& other) const;
    bool operator<=(const ReverseIterator& other) const;
};

template <typename T>
class ConstReverseIterator : public ReverseIterator<const T> {
   public:
    ConstReverseIterator() : ReverseIterator<const T>() {};
    ConstReverseIterator(const T* pointer)
        : ReverseIterator<const T>(pointer) {};
};
#endif
