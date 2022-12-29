# Programming assignment: Implement the functions declared in the header file

You are given the header file phone_number.h, which contains declaration of the PhoneNumber class. The comments describe the behavior that is expected from the implementation of this class.

    # pragma once

    # include <string>

    using namespace std;

    class PhoneNumber {
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
      explicit PhoneNumber(const string &international_number);

      string GetCountryCode() const;
      string GetCityCode() const;
      string GetLocalNumber() const;
      string GetInternationalNumber() const;

    private:
      string country_code_;
      string city_code_;
      string local_number_;
    };

Send a cpp file with method definitions of PhoneNumber class that implements this behavior.
