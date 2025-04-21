#include "vector.h"

template <typename T>
void Vector<T>::reallocate(size_t new_capacity)
{
    T *new_data = allocator.allocate(new_capacity);

    for (int i = 0; i < size_; i++)
    {
        allocator.construct(new_data + i, std::move(data[i]));
        allocator.destroy(data + i);
    }

    allocator.deallocate(data, capacity_);
    data = new_data;
    capacity_ = new_capacity;
}

template <typename T>
Vector<T>::Vector(size_t size)
    : size_(size), capacity_(size)
{
    data = allocator.allocate(size);

    for (int i = 0; i < size; i++)
    {
        allocator.construct(data + i);
    }
}

template <typename T>
Vector<T>::Vector(size_t size, const T &value)
    : size_(size), capacity_(size)
{
    data = allocator.allocate(size);

    for (int i = 0; i < size; i++)
    {
        allocator.construct(data + i, value);
    }
}

template <typename T>
Vector<T>::Vector(const Vector &other)
    : size_(other.size()), capacity_(other.capacity())
{
    data = allocator.allocate(capacity_);

    for (int i = 0; i < size; i++)
    {
        allocator.construct(data + i, other.data[i]);
    }
}

template <typename T>
Vector<T>::Vector(Vector&& other) noexcept
    : size_(other.size()), capacity_(other.capacity()), data(other.data)
{
    other.data = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

template <typename T>
Vector<T>::~Vector(){
    this->clear();
    allocator.deallocate(data, capacity_);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T> &other){
    if (this != &other){
        this->clear();

        this->reserve(other.capacity());

        for (int i = 0; i < other.size(); i++){
            allocator.construct(data + i, other.data[i]);
        }
        size_ = other.size();
    }

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> &&other) noexcept{
    if (this != &other){
        data = other.data;
        capacity_ = other.capacity();
        size_ = other.size();

        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    return *this;
}

template <typename T>
void Vector<T>::assign(size_t count, const T &value){
    this->clear();

    this->reserve(count);

    for (int i = 0; i < count; i++){
        allocator.construct(data + i, value);
    }

    size_ = count;
}

template <typename T>
T &Vector<T>::at(size_t pos)
{
    if (pos >= size_)
    {
        throw std::out_of_range("Access element out of border");
    }
    return data[pos];
}

template <typename T>
const T &Vector<T>::at(size_t pos) const
{
    if (pos >= size_)
    {
        throw std::out_of_range("Access element out of border");
    }
    return data[pos];
}

template <typename T>
T &Vector<T>::operator[](size_t pos)
{
    return data[pos];
}

template <typename T>
const T &Vector<T>::operator[](size_t pos) const
{
    return data[pos];
}

template <typename T>
T &Vector<T>::front(){
    return data[0];
}

template <typename T>
const T &Vector<T>::front() const{
    return data[0];
}

template <typename T>
T &Vector<T>::back(){
    return data[size_ - 1];
}

template <typename T>
const T &Vector<T>::back() const{
    return data[size_ - 1];
}

template <typename T>
T *Vector<T>::getData(){
    return data;
}

template <typename T>
const T *Vector<T>::data_ptr() const{
    return data;
}

template <typename T>
bool Vector<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
size_t Vector<T>::size() const
{
    return size_;
}

template <typename T>
size_t Vector<T>::max_size() const{
    return allocator.max_size;
}

template <typename T>
void Vector<T>::reserve(size_t new_cap){
    if (capacity_ < new_cap){
        this->reallocate(new_cap);
    }
}

template <typename T>
size_t Vector<T>::capacity() const
{
    return capacity_;
}

template <typename T>
void Vector<T>::push_back(const T &value)
{
    if (size_ == capacity_)
    {
        size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
        this->reallocate(new_capacity);
    }

    allocator.construct(data + size_, value);
    size_++;
}

template <typename T>
void Vector<T>::pop_back()
{
    // if (this->empty){
    //     throw std::out_of_range("Wrong pop_back. Vector is empty")
    // }

    allocator.destroy(data + size_ - 1);
    size_--;
}

template <typename T>
void Vector<T>::clear()
{
    for (int i = 0; i < size_; i++)
    {
        allocator.destroy(data + i);
    }
    size_ = 0;
}

template <typename T>
void Vector<T>::resize(size_t count){
    if (count < size_){
        for (int i = count; i < size_; i++){
            allocator.destroy(data + i);
        }
    }
    else if(count > size_){
        if (count > capacity_){
            this->reallocate(count);
        }

        for (int i = size_; i < count; i++){
            allocator.construct(data + i);
        }
    }

    size_ = count;
}

template <typename T>
void Vector<T>::resize(size_t count, const T& value){
    if (count < size_){
        for (int i = count; i < size_; i++){
            allocator.destroy(data + i);
        }
    }
    else if(count > size_){
        reserve(count);

        for (int i = size_; i < count; i++){
            allocator.construct(data + i, value);
        }
    }

    size_ = count;
}

template <typename T>
void Vector<T>::swap(Vector &other){
    std::swap(this->data, other.data);
    std::swap(this->size_, other.size_);
    std::swap(this->capacity_, other.capacity_);
}