#include "person.hpp"

// constructor
Person::Person(const std::string& name, const std::string& surname, const std::string& address, const std::string& zipcode, const std::string& city, const std::string& nationality, const std::string& pesel, Gender gender)
    : name_(name)
    , surname_(surname)
    , address_(address)
    , zipcode_(zipcode)
    , city_(city)
    , nationality_(nationality)
    , pesel_(pesel)
    , gender_(gender) 
{}