#include "phone_number.h"
#include <iostream>

PhoneNumber::PhoneNumber(const std::string &international_number)
{
    std::istringstream iss(international_number);
    std::getline(iss, country_code_, '-');
    std::getline(iss, city_code_, '-');
    iss >> local_number_;
    // Check if the number is invalid
    if (country_code_[0] != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty())
    {
        throw std::invalid_argument("Invalid telephone number format");
    }
}

std::string PhoneNumber::GetCountryCode() const
{
    return country_code_;
}
std::string PhoneNumber::GetCityCode() const
{
    return city_code_;
}
std::string PhoneNumber::GetLocalNumber() const
{
    return local_number_;
}
std::string PhoneNumber::GetInternationalNumber() const
{
    return country_code_ + "-" + city_code_ + "-" + local_number_;
}