#include "macro_log.h"
#include "../../src/test_runner.h"

#define LOG(logger, message)      \
    {                             \
        logger.LogLine(__LINE__); \
        logger.LogFile(__FILE__); \
        logger.Log(message);      \
    }

void TestLog()
{
#line 1 "logger.cpp"

    ostringstream logs;
    Logger l(logs);
    LOG(l, "hello");

    l.SetLogFile(true);
    LOG(l, "hello");

    l.SetLogLine(true);
    LOG(l, "hello");

    l.SetLogFile(false);
    LOG(l, "hello");

    string expected = "hello\n";
    expected += "logger.cpp hello\n";
    expected += "logger.cpp:10 hello\n";
    expected += "Line 13 hello\n";
    ASSERT_EQUAL(logs.str(), expected);
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestLog);
}