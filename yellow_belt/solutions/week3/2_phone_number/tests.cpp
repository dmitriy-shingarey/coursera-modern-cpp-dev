#include "../../src/test_runner.h"
#include "phone_number.h"

void TestValidNumber()
{
    // Test valid phone number
    PhoneNumber phone("+7-495-111-22-33");
    AssertEqual(phone.GetCountryCode(), "+7");
    AssertEqual(phone.GetCityCode(), "495");
    AssertEqual(phone.GetLocalNumber(), "111-22-33");
    AssertEqual(phone.GetInternationalNumber(), "+7-495-111-22-33");
}

int main(int argc, char const *argv[])
{
    TestRunner tr;
    tr.RunTest(TestValidNumber, "TestValidNumber");

    // Test invalid phone number (missing '+')
    try
    {
        PhoneNumber phone("7-495-111-22-33");
        throw std::logic_error("Test case should have thrown an exception 1");
    }
    catch (const std::invalid_argument &)
    {
        // Exception was expected
    }

    // Test invalid phone number (missing city code)
    try
    {
        PhoneNumber phone("+7--111-22-33");
        throw std::logic_error("Test case should have thrown an exception 2");
    }
    catch (const std::invalid_argument &)
    {
        // Exception was expected
    }

    // Test invalid phone number (missing number)
    try
    {
        PhoneNumber phone("+7-495");
        throw std::logic_error("Test case should have thrown an exception 3");
    }
    catch (const std::invalid_argument &)
    {
        // Exception was expected
    }

    return 0;
}
