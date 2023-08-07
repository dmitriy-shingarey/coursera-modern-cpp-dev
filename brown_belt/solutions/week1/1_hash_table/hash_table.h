#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>

template <typename Type, typename Hasher>
class HashSet
{
public:
    using BucketList = std::forward_list<Type>;

public:
    explicit HashSet(
        std::size_t num_buckets,
        const Hasher &hasher = {});

    void Add(const Type &value);
    bool Has(const Type &value) const;
    void Erase(const Type &value);
    const BucketList &GetBucket(const Type &value) const
    {
        return data_.at(GetIndex(value));
    };
    auto GetIndex(const Type &value) const;

private:
    std::vector<BucketList> data_;
    Hasher hasher_;
};

#endif