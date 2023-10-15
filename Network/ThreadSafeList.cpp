#include "ThreadSafeList.hpp"
#include <algorithm>

template <typename T>
ThreadSafeList<T>::ThreadSafeList() = default;

template <typename T>
void ThreadSafeList<T>::push_back(const T& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    data_.push_back(value);
}

template <typename T>
void ThreadSafeList<T>::remove(const T& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    data_.remove(value);
}

template <typename T>
bool ThreadSafeList<T>::contains(const T& value) const {
    std::lock_guard<std::mutex> lock(mutex_);
    return std::find(data_.begin(), data_.end(), value) != data_.end();
}

template <typename T>
size_t ThreadSafeList<T>::size() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return data_.size();
}

template <typename T>
bool ThreadSafeList<T>::empty() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return data_.empty();
}

