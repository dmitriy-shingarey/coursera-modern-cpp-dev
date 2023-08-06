# Efficient use of associative containers

## [Programming Assignment: Hash Table](1_hash_table)

Now that you know how unordered containers are arranged internally, you are encouraged to implement a simplified version of a hash table yourself. Implement the ```HashSet``` template:

```cpp
template <typename Type, typename Hasher>
class HashSet {
public:
  using BucketList = forward_list<Type>;

public:
  Explicit HashSet(
      size_t num_buckets,
      const Hasher& hasher = {}
  );

  void Add(const Type& value);
  bool Has(const Type& value) const ;
  void Erase(const Type& value);
  const BucketList& GetBucket(const Type& value) const;
};
```

Requirements:

* There must be exactly ```num_buckets``` of buckets in your hash table at any given time. Rehashing should not be performed.
* The ```Add``` method must not change the contents of the table if an element equal to this one already exists in the table.
* The ```Has``` method should return ```true``` if and only if the element equal to the given one is already present in the table.
* The ```Erase``` method should erase an element equal to the given one from the table if it is there, otherwise it should not change the table contents.
* The ```GetBucket``` method should return a reference to a bucket that would contain the given element, regardless of whether it is in the table or not.