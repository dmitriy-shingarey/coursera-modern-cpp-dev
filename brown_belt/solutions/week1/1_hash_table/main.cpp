#include "../../src/test_runner.h"
#include "hash_table.cpp"
#include "hash_table.h"
#include <functional>

struct IntHasher
{
    size_t operator()(int value) const
    {
        // Это реальная хеш-функция из libc++, libstdc++.
        // Чтобы она работала хорошо, std::unordered_map
        // использует простые числа для числа бакетов
        return value;
    }
};

void TestSmoke()
{
    HashSet<int, IntHasher> hash_set(10, IntHasher());

    // test non-existing 3,4
    ASSERT(!hash_set.Has(3));
    ASSERT(!hash_set.Has(4));

    // test insertion 3
    hash_set.Add(3);
    ASSERT(hash_set.Has(3));
    ASSERT(!hash_set.Has(4));

    // test deletion 3
    hash_set.Erase(3);
    ASSERT(!hash_set.Has(3));
    ASSERT(!hash_set.Has(4));
}

void TestEmpty()
{
    HashSet<int, IntHasher> hash_set(10, IntHasher());
    for (int value = 0; value < 1000; ++value)
    {
        ASSERT(!hash_set.Has(value));
    }
    // hash_set.Add(2);
}

void TestAddingSameElement()
{
    HashSet<int, IntHasher> hash_set(10, IntHasher());
    ASSERT(!hash_set.Has(3));
    hash_set.Add(3);
    ASSERT(hash_set.Has(3));
    hash_set.Add(3);
    ASSERT(hash_set.Has(3));
}

void TestAddingToTheSameBasket()
{
    HashSet<int, IntHasher> hash_set(10, IntHasher());
    ASSERT(!hash_set.Has(3));
    ASSERT(!hash_set.Has(13));
    hash_set.Add(3);
    ASSERT(hash_set.Has(3));
    ASSERT(!hash_set.Has(13));
    hash_set.Add(13);
    ASSERT(hash_set.Has(3));
    ASSERT(hash_set.Has(13));
}

void TestGetBucket()
{
    HashSet<int, IntHasher> hash_set(10, IntHasher());
    hash_set.Add(2);
    hash_set.Add(3);

    ASSERT(hash_set.Has(2));
    ASSERT(hash_set.Has(3));

    const auto &bucket = hash_set.GetBucket(2);
    const auto &three_bucket = hash_set.GetBucket(3);
    ASSERT(&bucket != &three_bucket);

    ASSERT_EQUAL(1, distance(begin(bucket), end(bucket)));
    // ASSERT_EQUAL(2, bucket.front().value);
}

int main(int argc, char const *argv[])
{
    TestRunner tr;
    RUN_TEST(tr, TestEmpty);
    RUN_TEST(tr, TestSmoke);
    RUN_TEST(tr, TestAddingSameElement);
    RUN_TEST(tr, TestAddingToTheSameBasket);
    RUN_TEST(tr, TestGetBucket);
    return 0;
}
