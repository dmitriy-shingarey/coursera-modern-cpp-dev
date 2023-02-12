#include "iterator_range.h"

template <typename Iterator>

class Paginator
{

private:
    size_t _page_size;
    std::vector<IteratorRange<Iterator>> _pages;

public:
    Paginator(Iterator begin_it, Iterator end_it, size_t page_size) : _page_size(page_size)
    {
        while (begin_it != end_it)
        {
            _pages.push_back(MakePage(begin_it, end_it, _page_size));
            begin_it = _pages[_pages.size() - 1].end();
        }
    };

    auto begin() const { return _pages.begin(); }

    auto end() const { return _pages.end(); }

    size_t size() const { return _pages.size(); }
};

template <typename Container>
auto Paginate(Container &c, size_t page_size)
{
    return Paginator(c.begin(), c.end(), page_size);
}