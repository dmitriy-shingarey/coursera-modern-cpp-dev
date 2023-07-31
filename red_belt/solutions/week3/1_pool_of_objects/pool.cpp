#include "pool_.h"
#include <algorithm>

template <class T>
T *Objectpool_<T>::TryAllocate()
{
    if (deallocated_pool_.empty())
    {
        return nullptr;
    }
    else
    {
        auto pObj = deallocated_pool_.front(); // take the oldest reference in queue
        allocated_pool_.insert(pObj);          // add the reference to allocated pool_ set
        deallocated_pool_.pop();               // remove the oldest reference in queue
        return pObj;
    }
}

template <class T>
T *Objectpool_<T>::Allocate()
{
    auto pObj = TryAllocate();
    if (!pObj) // if nullptr, create new object and add to the allocated pool_ set
    {
        pObj = new T;
        allocated_pool_.insert(pObj);
    }
    return pObj;
}

template <class T>
void Objectpool_<T>::Deallocate(T *pObj)
{
    if (allocated_pool_.find(pObj) == allocated_pool_.end())
    {
        throw std::invalid_argument("Object is not present.");
    }
    allocated_pool_.erase(pObj);
    deallocated_pool_.push(pObj);
}
