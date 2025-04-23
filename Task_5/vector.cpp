#include "vector.h"
#include "iterator.h"

template <typename T>
void Vector<T>::reallocate(size_t new_capacity) {
    T* new_data = allocator.allocate(new_capacity);


    for (int i = 0; i < size_; i++) {
        allocator.construct(new_data + i, std::move(data[i]));
        allocator.destroy(data + i);
    }

    allocator.deallocate(data, capacity_);
    data = new_data;
    capacity_ = new_capacity;
}

template <typename T>
Vector<T>::Vector(size_t size) : size_(size), capacity_(size) {
    data = allocator.allocate(size);


    for (int i = 0; i < size; i++) {
        allocator.construct(data + i);
    }
}

template <typename T>
Vector<T>::Vector(size_t size, const T& value) : size_(size), capacity_(size) {
    data = allocator.allocate(size);


    for (int i = 0; i < size; i++) {
        allocator.construct(data + i, value);
    }
}

template <typename T>
template <typename InputIt, typename>
Vector<T>::Vector(InputIt first, InputIt last) {
    capacity_ = last - first;
    size_ = capacity_;
    data = allocator.allocate(capacity_);


    for (size_t i = 0; first != last; first++, i++) {
        allocator.construct(data + i, *first);
    }
}

template <typename T>
Vector<T>::Vector(const Vector& other)
    : size_(other.size()), capacity_(other.capacity()) {
    data = allocator.allocate(capacity_);


    for (int i = 0; i < size_; i++) {
        allocator.construct(data + i, other.data[i]);
    }
}

template <typename T>
Vector<T>::Vector(Vector&& other) noexcept
    : size_(other.size()), capacity_(other.capacity()), data(other.data) {
    other.data = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

// template <typename T>
// Vector<T>::~Vector() {
//     this->clear();
//     allocator.deallocate(data, capacity_);
// }

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {


    if (this != &other) {
        this->clear();

        this->reserve(other.capacity());

        for (int i = 0; i < other.size(); i++) {
            allocator.construct(data + i, other.data[i]);
        }
        size_ = other.size();
    }

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {


    if (this != &other) {
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
void Vector<T>::assign(size_t count, const T& value) {
    this->clear();

    this->reserve(count);


    for (int i = 0; i < count; i++) {
        allocator.construct(data + i, value);
    }

    size_ = count;
}

template <typename T>
template <typename InputIt, typename>
void Vector<T>::assign(InputIt first, InputIt last) {
    this->clear();

    size_t count = last - first;
    this->reserve(count);


    for (size_t i = 0; first != last; first++, i++) {
        allocator.construct(data + i, *first);
    }
    size_ = count;
}

template <typename T>
T& Vector<T>::at(size_t pos) {


    if (pos >= size_) {
        throw std::out_of_range("Access element out of border");
    }
    return data[pos];
}

template <typename T>
const T& Vector<T>::at(size_t pos) const {


    if (pos >= size_) {
        throw std::out_of_range("Access element out of border");
    }
    return data[pos];
}

template <typename T>
T& Vector<T>::operator[](size_t pos) {
    return data[pos];
}

template <typename T>
const T& Vector<T>::operator[](size_t pos) const {
    return data[pos];
}

template <typename T>
T& Vector<T>::front() {
    return data[0];
}

template <typename T>
const T& Vector<T>::front() const {
    return data[0];
}

template <typename T>
T& Vector<T>::back() {
    return data[size_ - 1];
}

template <typename T>
const T& Vector<T>::back() const {
    return data[size_ - 1];
}

template <typename T>
T* Vector<T>::data_ptr() {
    return data;
}

template <typename T>
const T* Vector<T>::data_ptr() const {
    return data;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return iterator(data);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return iterator(data + size_);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const {
    return const_iterator(data);
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const {
    return const_iterator(data + size_);
}

template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin() {
    return reverse_iterator(data + size_);
}

template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend() {
    return reverse_iterator(data);
}

template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::rcbegin() const {
    return const_reverse_iterator(data + size_);
}

template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::rcend() const {
    return const_reverse_iterator(data);
}


template <typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template <typename T>
size_t Vector<T>::size() const {
    return size_;
}

template <typename T>
size_t Vector<T>::max_size() const {
    return allocator.max_size;
}

template <typename T>
void Vector<T>::reserve(size_t new_cap) {


    if (capacity_ < new_cap) {
        this->reallocate(new_cap);
    }
}

template <typename T>
size_t Vector<T>::capacity() const {
    return capacity_;
}

template <typename T>
void Vector<T>::push_back(const T& value) {


    if (size_ == capacity_) {
        size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
        this->reallocate(new_capacity);
    }

    allocator.construct(data + size_, value);
    size_++;
}

template <typename T>
void Vector<T>::pop_back() {
    // if (this->empty){
    //     throw std::out_of_range("Wrong pop_back. Vector is empty")
    // }

    allocator.destroy(data + size_ - 1);
    size_--;
}

template <typename T>
void Vector<T>::clear() {


    for (int i = 0; i < size_; i++) {
        allocator.destroy(data + i);
    }
    size_ = 0;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(Vector<T>::iterator pos,
                                               const T& value) {
    return insert(pos, 1, value);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(Vector<T>::iterator pos,
                                               T&& value) {
    std::ptrdiff_t index = pos - begin();


    if (size_ == capacity_) {
        size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
        this->reallocate(new_capacity);
    }

    pos = begin() + index;


    for (size_t i = size_ - 1; i >= index; i--) {
        allocator.construct(data + i + 1, std::move(data[i]));
        allocator.destroy(data + i);
        if (i == 0) {
            break;
        }
    }

    allocator.construct(data + index, std::move(value));
    size_++;

    return pos;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(typename Vector<T>::iterator pos,
                                               size_t count, const T& value) {


    if (count == 0) {
        return pos;
    }

    std::ptrdiff_t index = pos - begin();


    if (size_ + count > capacity_) {
        size_t new_capacity = std::max(2 * capacity_, size_ + count);
        this->reallocate(new_capacity);
    }
    pos = begin() + index;


    for (size_t i = size_ - 1; i >= index; i--) {
        allocator.construct(data + i + count, std::move(data[i]));
        allocator.destroy(data + i);
        if (i == 0) {
            break;
        }
    }


    for (size_t i = 0; i < count; i++) {
        allocator.construct(data + index + i, value);
    }

    size_ += count;
    return pos;
}

template <typename T>
template <typename InputIt, typename>
typename Vector<T>::iterator Vector<T>::insert(Vector<T>::iterator pos,
                                               InputIt first, InputIt last) {
    size_t count = last - first;


    if (count == 0) {
        return pos;
    }

    std::ptrdiff_t index = pos - begin();


    if (size_ + count > capacity_) {
        size_t new_capacity = std::max(2 * capacity_, size_ + count);
        this->reallocate(new_capacity);
    }
    pos = begin() + index;


    for (size_t i = size_ - 1; i >= index; i--) {
        allocator.construct(data + i + count, std::move(data[i]));
        allocator.destroy(data + i);
        if (i == 0) {
            break;
        }
    }


    for (size_t i = 0; first != last; first++, i++) {
        allocator.construct(data + index + i, *first);
    }

    size_ += count;
    return pos;
}

template <typename T>
template <typename... Args>
typename Vector<T>::iterator Vector<T>::emplace(Vector<T>::iterator pos,
                                                Args&&... args) {
    std::ptrdiff_t index = pos - begin();


    if (size_ == capacity_) {
        size_t new_capacity = capacity_ == 0 ? 1 : 2 * capacity_;
        this->reallocate(new_capacity);
    }
    pos = begin() + index;


    for (size_t i = size_ - 1; i >= index; i--) {
        allocator.construct(data + i + 1, std::move(data[i]));
        allocator.destroy(data + i);
        if (i == 0) {
            break;
        }
    }

    allocator.construct(data + index, std::forward<Args>(args)...);
    size_++;

    return pos;
}

template <typename T>
template <typename... Args>
T& Vector<T>::emplace_back(Args&&... args) {


    if (size_ == capacity_) {
        this->reallocate(2 * capacity_);
    }

    allocator.construct(data + size_, std::forward<Args>(args)...);
    size_++;

    return data[size_ - 1];
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(Vector<T>::iterator pos) {
    std::ptrdiff_t index = pos - begin();

    allocator.destroy(data + index);


    for (size_t i = index + 1; i < size_; i++) {
        allocator.construct(data + i - 1, std::move(data[i]));
        allocator.destroy(data + i);
    }

    size_--;
    return pos;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(Vector<T>::iterator first,
                                              Vector<T>::iterator last) {
    std::ptrdiff_t index_first = first - begin();
    std::ptrdiff_t index_last = last - begin();


    for (size_t i = index_first; i < index_last; i++) {
        allocator.destroy(data + i);
    }

    std::ptrdiff_t count = index_last - index_first;


    for (size_t i = index_last; i < size_; i++) {
        allocator.construct(data - count + i, std::move(data[i]));
        allocator.destroy(data + i);
    }

    size_ -= count;
    return first;
}

template <typename T>
void Vector<T>::resize(size_t count) {


    if (count < size_) {
        for (int i = count; i < size_; i++) {
            allocator.destroy(data + i);
        }
    }


    else if (count > size_) {
        if (count > capacity_) {
            this->reallocate(count);
        }

        for (int i = size_; i < count; i++) {
            allocator.construct(data + i);
        }
    }

    size_ = count;
}

template <typename T>
void Vector<T>::resize(size_t count, const T& value) {


    if (count < size_) {
        for (int i = count; i < size_; i++) {
            allocator.destroy(data + i);
        }
    }


    else if (count > size_) {
        reserve(count);

        for (int i = size_; i < count; i++) {
            allocator.construct(data + i, value);
        }
    }

    size_ = count;
}

template <typename T>
void Vector<T>::swap(Vector& other) {
    std::swap(this->data, other.data);
    std::swap(this->size_, other.size_);
    std::swap(this->capacity_, other.capacity_);
}
