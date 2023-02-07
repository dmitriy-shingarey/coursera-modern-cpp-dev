#include "../../src/test_runner.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Table
{
private:
    size_t rows_;
    size_t columns_;
    vector<vector<T>> table_;

public:
    Table(size_t rows, size_t columns) : rows_(rows),
                                         columns_(columns)
    {
        table_.resize(rows_, vector<int>(columns_));
    };
    void Resize(size_t rows, size_t columns)
    {
        rows_ = rows;
        columns_ = columns;
        table_.resize(rows_);
        for (int i = 0; i < table_.size(); ++i)
            table_[i].resize(columns_);
    };
    pair<size_t, size_t> Size()
    {
        return {rows_, columns_};
    }

    const vector<T> &operator[](const size_t index) const
    {
        return table_[index];
    }

    vector<T> &operator[](const size_t index)
    {
        return table_[index];
    }
};

void Tests()
{
    Table<int> t(2, 3);
    ASSERT_EQUAL(t.Size().first, 2u);
    ASSERT_EQUAL(t.Size().second, 3u);

    t[0][0] = 18;
    ASSERT_EQUAL(t[0][0], 18);

    t.Resize(4, 6);
    ASSERT_EQUAL(t.Size().first, 4u);
    ASSERT_EQUAL(t.Size().second, 6u);
}

int main(int argc, char const *argv[])
{
    TestRunner tr;
    RUN_TEST(tr, Tests);
    return 0;
}
