#include <vector>

template <typename Iterator>

struct IteratorRange
{
    Iterator first, last;

    Iterator begin() const
    {
        return first;
    }
    Iterator end() const
    {
        return last;
    }
};

template <typename T>
IteratorRange<typename std::vector<T>::iterator> Head(std::vector<T> &v, std::size_t top){
    return {
        v.begin(),
        next(v.begin, std::min(top, v.size()))}};

template <typename Iterator>
IteratorRange<Iterator> MakeRange(Iterator begin, Iterator end)
{
    return IteratorRange<Iterator>(begin, end);
}

int main(int argc, char const *argv[])
{

    return 0;
}
