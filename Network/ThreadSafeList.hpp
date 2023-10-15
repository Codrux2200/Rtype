#pragma once

#include <list>
#include <mutex>

template <typename T>
class ThreadSafeList {
public:
    ThreadSafeList();

    void push_back(const T& value);
    void remove(const T& value);
    bool contains(const T& value) const;
    size_t size() const;
    bool empty() const;

private:
    std::list<T> data_;
    mutable std::mutex mutex_;
};

#include "ThreadSafeList.cpp" // Include the source file at the end
