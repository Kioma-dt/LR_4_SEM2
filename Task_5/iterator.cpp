#include "iterator.h"

template <typename T>
typename Iterator<T>::reference Iterator<T>::operator*() const{
    return *ptr;
}

template <typename T>
typename Iterator<T>::pointer Iterator<T>::operator->() const{
    return ptr;
}

template <typename T>
Iterator<T> &Iterator<T>::operator++(){
    ++ptr;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int){
    Iterator temp = *this;
    ++ptr;
    return temp;
}

template <typename T>
Iterator<T> &Iterator<T>::operator--(){
    --ptr;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int){
    Iterator temp = *this;
    --ptr;
    return temp;
}

template <typename T>
Iterator<T> Iterator<T>::operator+(difference_type n) const{
    return Iterator(ptr + n);
}

template <typename T>
Iterator<T> Iterator<T>::operator-(difference_type n) const{
    return Iterator(ptr - n);
}

template <typename T>
typename Iterator<T>::difference_type Iterator<T>::operator-(const Iterator &other) const{
    return ptr - other.ptr;
}

template <typename T>
typename Iterator<T>::reference Iterator<T>::operator[](difference_type n) const{
    return *(ptr + n);
}

template <typename T>
bool Iterator<T>::operator==(const Iterator &other) const{
    return ptr == other.ptr;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator &other) const{
    return ptr != other.ptr;
}

template <typename T>
bool Iterator<T>::operator>(const Iterator &other) const{
    return ptr > other.ptr;
}

template <typename T>
bool Iterator<T>::operator<(const Iterator &other) const{
    return ptr < other.ptr;
}

template <typename T>
bool Iterator<T>::operator>=(const Iterator &other) const{
    return ptr >= other.ptr;
}

template <typename T>
bool Iterator<T>::operator<=(const Iterator &other) const{
    return ptr <= other.ptr;
}



// REVERSE ITERATOR



template <typename T>
typename ReverseIterator<T>::reference ReverseIterator<T>::operator*() const{
    return *(ptr - 1);
}

template <typename T>
typename ReverseIterator<T>::pointer ReverseIterator<T>::operator->() const{
    return ptr - 1;
}

template <typename T>
ReverseIterator<T> &ReverseIterator<T>::operator++(){
    --ptr;
    return *this;
}

template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator++(int){
    ReverseIterator temp = *this;
    --ptr;
    return temp;
}

template <typename T>
ReverseIterator<T> &ReverseIterator<T>::operator--(){
    ++ptr;
    return *this;
}

template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator--(int){
    ReverseIterator temp = *this;
    ++ptr;
    return temp;
}

template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator+(difference_type n) const{
    return ReverseIterator(ptr - n);
}

template <typename T>
ReverseIterator<T> ReverseIterator<T>::operator-(difference_type n) const{
    return ReverseIterator(ptr + n);
}

template <typename T>
typename ReverseIterator<T>::difference_type ReverseIterator<T>::operator-(const ReverseIterator &other) const{
    return other.ptr - ptr;
}

template <typename T>
typename ReverseIterator<T>::reference ReverseIterator<T>::operator[](difference_type n) const{
    return *(*this + n);
}

template <typename T>
bool ReverseIterator<T>::operator==(const ReverseIterator &other) const{
    return ptr == other.ptr;
}

template <typename T>
bool ReverseIterator<T>::operator!=(const ReverseIterator &other) const{
    return ptr != other.ptr;
}

template <typename T>
bool ReverseIterator<T>::operator>(const ReverseIterator &other) const{
    return ptr < other.ptr;
}

template <typename T>
bool ReverseIterator<T>::operator<(const ReverseIterator &other) const{
    return ptr > other.ptr;
}

template <typename T>
bool ReverseIterator<T>::operator>=(const ReverseIterator &other) const{
    return ptr <= other.ptr;
}

template <typename T>
bool ReverseIterator<T>::operator<=(const ReverseIterator &other) const{
    return ptr >= other.ptr;
}