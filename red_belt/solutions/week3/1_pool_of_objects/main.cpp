#include "pool.h"
#include "pool.cpp"
#include "../../src/test_runner.h"
#include <string>

void TestObjectPool()
{
    ObjectPool<int> MyPool1;

    ASSERT_EQUAL(MyPool1.TryAllocate(), nullptr);

    auto p1 = MyPool1.Allocate();
    auto p2 = MyPool1.Allocate();
    auto p3 = MyPool1.Allocate();

    *p1 = 1;
    *p2 = 2;
    *p3 = 3;

    MyPool1.Deallocate(p2);
    ASSERT_EQUAL(*MyPool1.Allocate(), 2);

    MyPool1.Deallocate(p3);
    MyPool1.Deallocate(p1);
    ASSERT_EQUAL(*MyPool1.Allocate(), 3);
    ASSERT_EQUAL(*MyPool1.Allocate(), 1);

    MyPool1.Deallocate(p1);
}

int main(int argc, char const *argv[])
{
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
