#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <forward_list>
#include <vector>

template <typename Type, typename Hasher>
class HashSet
{
public:
    using BucketList = forward_list<Type>;

public:
    explicit HashSet(
        size_t num_buckets,
        const Hasher &hasher = {})
        : data_(num_buckets), hasher_(hasher){};

    void Add(const Type &value);
    bool Has(const Type &value) const;
    void Erase(const Type &value);
    const BucketList &GetBucket(const Type &value) const;

private:
    std::vector<BucketList> data_;
    Hasher &hasher_;
};

#endif