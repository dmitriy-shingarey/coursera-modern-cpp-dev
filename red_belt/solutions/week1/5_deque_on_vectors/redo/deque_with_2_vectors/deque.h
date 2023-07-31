#include <vector>

template <typename T>
class Deque
{
private:
    /* data */

    std::vector<T> v_front;
    std::vector<T> v_back;

    void check_index(const size_t index)
    {
        if (index >= Size())
        {
            throw std::out_of_range("out of range");
        }
    }

public:
    Deque() = default;
    Deque(std::vector<T> &v);
    ~Deque();

    bool Empty() const {};

    std::size_t Size(){};

    T &operator[](std::size_t index);

    const T &operator[](std::size_t index) const;

    T &At(std::size_t index){};

    T &At(std::size_t index) const {};

    T &Front(){};

    const T &Front() const {};

    T &Back(){};

    const T &Back() const {};

    void PushFront(){};

    void PushBack(){};
};
