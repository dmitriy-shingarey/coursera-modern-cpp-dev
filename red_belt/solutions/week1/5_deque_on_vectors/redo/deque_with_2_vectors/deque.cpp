#include "deque.h"

template <typename T>
Deque<T>::Deque(std::vector<T> &v) : v_back(v){};

template <typename T>
T &Deque<T>::operator[](std::size_t index)
{
    if (index > v_front.size - 1)
    {
        return v_back[index - v_front.size()];
    }
    return v_front[v_front.size() - index - 1];
};

template <typename T>
const T &Deque<T>::operator[](std::size_t index) const
{
    if (index > v_front.size - 1)
    {
        return v_back[index - v_front.size()];
    }
    return v_front[v_front.size() - index - 1];
};

template <typename T>
bool Deque<T>::Empty() const
{
    if ((v_back.size() != 0) || (v_front.size() != 0))
    {
        return false;
    }
    return true;
}

template <typename T>
std::size_t Deque<T>::Size()
{
    return {v_back.size() + v_front.size()};
}

template <typename T>
T &Deque<T>::At(std::size_t index)
{
    check_index(index);
    return operator[](index);
}

template <typename T>
T &Deque<T>::At(std::size_t index) const
{
    check_index(index);
    return operator[](index);
}