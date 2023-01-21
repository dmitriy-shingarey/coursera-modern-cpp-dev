#include <algorithm>

using namespace std;

template <typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
{
    ForwardIterator max_element = find_if(first, last, pred);

    for (auto it = max_element; it != last; it++)
    {
        if (*it > *max_element && pred(*it))
        {
            max_element = it;
        }
    }
    return max_element;
}
