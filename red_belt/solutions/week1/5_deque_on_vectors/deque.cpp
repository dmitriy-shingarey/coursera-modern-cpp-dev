#include "deque.h"
#include "tests.h"

int main(int argc, char const *argv[])
{
    TestRunner tr;
    RUN_TEST(tr, TestEmpty);
    RUN_TEST(tr, TestSize);
    RUN_TEST(tr, TestOperator);
    RUN_TEST(tr, TestAt);
    RUN_TEST(tr, TestFront);

    return 0;
}
