#include "../../src/test_runner.h"
#include <iostream>
#include <vector>

template <typename T>
class Deque
{
private:
    vector<T> v_front;
    vector<T> v_back;

    void CheckIndex(const size_t index)
    {
        if (index >= Size())
        {
            throw std::out_of_range("out of range");
        }
    }

public:
    Deque() = default;
    Deque(vector<T> v) : v_back(v){};

    bool Empty()
    {
        if ((v_front.size() != 0) || (v_back.size() != 0))
        {
            return false;
        }
        return true;
    };

    size_t Size()
    {
        return v_front.size() + v_back.size();
    }

    void PushFront(const T &val)
    {
        v_front.push_back(val);
    }

    void PushBack(const T &val)
    {
        v_back.push_back(val);
    }

    T &Front()
    {
        if (v_front.empty())
        {
            v_back.front();
        }
        return v_front.back();
    }

    const T &Front() const
    {
        if (v_front.empty())
        {
            v_back.front();
        }
        return v_front.back();
    }

    T &Back()
    {
        if (v_back.empty())
        {
            v_front.front();
        }
        return v_back.back();
    }

    const T &Back() const
    {
        if (v_back.empty())
        {
            v_front.front();
        }
        return v_back.back();
    }

    const T &operator[](const size_t index) const
    {
        if (index > (v_front.size() - 1))
        {
            return v_back[index - v_front.size()];
        }
        return v_front[v_front.size() - index - 1];
    }

    T &operator[](const size_t index)
    {
        if (index > (v_front.size()) - 1)
        {
            return v_back[index - v_front.size()];
        }
        return v_front[v_front.size() - index - 1];
    }

    T &At(size_t index)
    {

        CheckIndex(index);
        return operator[](index);
    }

    const T &At(size_t index) const
    {
        CheckIndex(index);
        return operator[](index);
    }
};
