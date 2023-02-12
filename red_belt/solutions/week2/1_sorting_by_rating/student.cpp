#include "student.h"
#include "../../src/profiler.h"

bool Compare(Student first, Student second)
{
    return first.Less(second);
}

// use const reference instead of copy
bool CompareFast(const Student &first, const Student &second)
{
    return first.Less(second);
}

int main(int argc, char const *argv[])
{
    Student S1;
    S1.rating = 0.4;
    Student S2;
    S2.rating = 0.7;

    {
        LOG_DURATION("Compare");
        for (size_t i = 0; i < 10000; i++)
        {
            Compare(S1, S2);
        }
    }
    {
        LOG_DURATION("CompareFast");
        for (size_t i = 0; i < 10000; i++)
        {
            CompareFast(S1, S2);
        }
    }
    return 0;
}