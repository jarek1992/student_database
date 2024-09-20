#include "peselValidator.hpp"
#include <iostream>
#include <regex>

bool Validator::validatePeselNumber(const std::string& pesel, size_t day, size_t month, size_t year) {
    if (day == 0 || month == 0 || year == 0) {
        std::cout << "Missing required data about date of birth " << std::endl;
        return false;
    }
    if (pesel.length() != 11) {
        return false;
    }

    int weights[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        sum += (pesel[i] - '0') * weights[i];
    }
    
    int controlDigit = (10 - (sum % 10)) % 10;

    if (controlDigit != (pesel[10] - '0')) {
        return false;
    }
    // reading number of year, month and day from pesel
    int peselYear = std::stoi(pesel.substr(0, 2));
    int peselMonth = std::stoi(pesel.substr(2, 2));
    int peselDay = std::stoi(pesel.substr(4, 2));
    // recognizing century and recalculating full year
    if (peselMonth >= 1 && peselMonth <= 12) {
        peselYear += 1900;
    } else if (month >= 21 && peselMonth <= 32) {
        peselYear += 2000;
        peselMonth -= 20;
    } else if (peselMonth >= 41 && peselMonth <= 52) {
        peselYear += 2100;
        peselMonth -= 40;
    } else if (peselMonth >= 61 && peselMonth <= 72) {
        peselYear += 2200;
        peselMonth -= 60;
    } else if (peselMonth >= 81 && peselMonth <= 92) {
        peselYear += 1800;
        peselMonth -= 80;
    } else {
        std::cout << "incorrect month in PESEL!" << std::endl;
        // incorrect month
        return false;
    }
    // checking matching with dates from pesel
    if (peselYear != year || peselMonth != month || peselDay != day) {
        std::cout << "Date of birth in PESEL not matching with your previous data!" << std::endl;
        return false;
    }
    return true;
}
