#pragma once

#include <sstream>
#include <string>

class PhoneNumber
{
public:
    /* Receives string in format +XXX-YYYY-ZZZZZZZZ
         The part from '+' to the first '-' is the country code.
         The part between the first and second '-' is the city code
         Anything after the second '-' character is a local number.
         The country code, city code and local number must not be empty.
         If string does not match this format, you should throw an invalid_argument exception.
         There is no need to check that the number contains only digits.

         Examples:
         * +7-495-111-22-33
         * +7-495-1112233
         * +323-22-460002
         * +1-2-coursera-cpp
         * 1-2-333 - invalid number - does not start with '+'
         +7-1233 - invalid number - only country and area code
    */
    explicit PhoneNumber(const std::string &international_number);

    std::string GetCountryCode() const;
    std::string GetCityCode() const;
    std::string GetLocalNumber() const;
    std::string GetInternationalNumber() const;

private:
    std::string country_code_;
    std::string city_code_;
    std::string local_number_;
};