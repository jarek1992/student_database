#pragma once

#include <string>

class Validator {
public:
  static bool validatePeselNumber(const std::string& pesel, const size_t day, const size_t month, const size_t year);
};