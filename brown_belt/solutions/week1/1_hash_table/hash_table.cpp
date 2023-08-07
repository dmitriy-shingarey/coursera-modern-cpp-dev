#include "hash_table.h"

template <typename Type, typename Hasher>
auto HashSet<Type, Hasher>::GetIndex(const Type &value) const
{
    return hasher_(value) % data_.size();
}

template <typename Type, typename Hasher>
HashSet<Type, Hasher>::HashSet(std::size_t num_buckets, const Hasher &hasher) : data_(num_buckets), hasher_{hasher} {};

template <typename Type, typename Hasher>
void HashSet<Type, Hasher>::Add(const Type &value)
{
    if (!Has(value))
    {
        data_[GetIndex(value)].push_front(value);
    }
    return;
};

template <typename Type, typename Hasher>
bool HashSet<Type, Hasher>::Has(const Type &value) const
{
    auto index = GetIndex(value);
    return {std::find(data_[index].begin(), data_[index].end(), value) != data_[index].end()};
};

template <typename Type, typename Hasher>
void HashSet<Type, Hasher>::Erase(const Type &value)
{
    data_[GetIndex(value)].remove(value);
};

// template <typename Type, typename Hasher>
// const HashSet<Type, Hasher>::BucketList &GetBucket(const Type &value) const
//{
//     return data_.at(GetIndex(value));
// };
