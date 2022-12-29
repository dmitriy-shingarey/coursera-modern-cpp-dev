#include "sum_reverse_sort.h"
#include "../../src/test_runner.h"
#include <algorithm>

int Sum(int x, int y)
{
    return {x + y};
}
string Reverse(string s)
{
    std::reverse(std::begin(s), std::end(s));

    return s;
}
void Sort(vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
}

// TESTS
void TestSum()
{
    AssertEqual(Sum(1, 2), 3, "1+2=3");
    AssertEqual(Sum(1, -2), -1, "1+2=3");
}

void TestReverseString()
{
    AssertEqual(Reverse("s"), "s", "s = s");
    AssertEqual(Reverse("sas"), "sas", "sas = sas");
    AssertEqual(Reverse("sasap"), "pasas", "pasas = sasap");
}

void TestSortVector()
{
    vector<int> v1{1};
    vector<int> v1_{1};
    Sort(v1);
    AssertEqual(v1, v1_, "[1] = [1]");
    vector<int> v2{2, 1};
    vector<int> v2_{1, 2};
    Sort(v2);
    AssertEqual(v2, v2_, "[2, 1] = [1, 2]");
    vector<int> v3{1, 5, 4, 3};
    vector<int> v3_{1, 3, 4, 5};
    Sort(v3);
    AssertEqual(v3, v3_, "[1,5,4,3] = [1,3,4,5]");
}

int main(int argc, char const *argv[])
{
    // RUN TESTS
    TestRunner tr;
    tr.RunTest(TestSum, "TestSum");
    tr.RunTest(TestReverseString, "TestReverseString");
    tr.RunTest(TestSortVector, "TestSortVector");
    return 0;
}
