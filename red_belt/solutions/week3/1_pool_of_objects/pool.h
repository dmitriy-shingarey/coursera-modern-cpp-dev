#pragma once

#include <queue>
#include <set>
#include <stdexcept>

template <class T>
class ObjectPool
{
public:
    ObjectPool() = default;

    T *Allocate();
    T *TryAllocate();

    void Deallocate(T *object);

private:
    std::queue<T *> deallocated_pool_;
    std::set<T *> allocated_pool_;
};