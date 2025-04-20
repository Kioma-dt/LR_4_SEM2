#include "vector.h"

template <typename T>
void Vector<T>::reallocate(size_t new_capacity){
    T *new_data = allocator.allocate(new_capacity);

    for (int i = 0; i < size_; i++){
        allocator.construct(new_data + i, std::move(data[i]));
        allocator.destroy(data + i);
    }
    
    allocator.deallocate(data, capacity_);
    data = new_data;
    capacity_ = new_capacity;
}



template <typename T>
size_t Vector<T>::size() const{
    return size_;
}

template <typename T>
size_t Vector<T>::capacity() const{
    return capacity_;
}



template <typename T>
void Vector<T>::push_back(const T& value){
    if (size_ == capacity_){
        size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
        this->reallocate(new_capacity);
    }

    allocator.construct(data + size_, value);
    size_++;
}

template <typename T>
void Vector<T>::pop_back(){
    // if (this->empty){
    //     throw std::out_of_range("Wrong pop_back. Vector is empty")
    // }

    allocator.destroy(data + size_ - 1);
    size_--;
}

template <typename T>
void Vector<T>::clear(){
    for (int i = 0; i < size_; i++){
        allocator.destroy(data + i);
    }
    size_ = 0;
}

template <typename T>
bool Vector<T>::empty() const{
    return size_ == 0;
}


template <typename T>
T& Vector<T>::at(size_t pos){
    if (pos >= size_){
        throw std::out_of_range("Access element out of border");
    }
    return data[pos];
}

template <typename T>
const T& Vector<T>::at(size_t pos) const{
    if (pos >= size_){
        throw std::out_of_range("Access element out of border");
    }
    return data[pos];
}

template <typename T>
T& Vector<T>::operator[](size_t pos){
    return data[pos];
}

template <typename T>
const T& Vector<T>::operator[](size_t pos) const{
    return data[pos];
}