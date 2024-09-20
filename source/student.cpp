#include "student.hpp"

Student::Student(const std::string& name, const std::string& surname, const size_t day, const size_t month, const size_t year, const std::string& address, const std::string& zipcode, const std::string& city, const std::string& nationality, const std::string& indexNumber, const std::string& pesel, Gender gender)
    : Person(name, surname, address, zipcode, city, nationality, pesel, gender)
    , day_(day)
    , month_(month)
    , year_(year)
    , indexNumber_(indexNumber) 
{}

//getters
  std::string Student::getName() const {
    return Person::getName();
  }
  std::string Student::getSurname() const {
    return Person::getSurname();
  }
  size_t Student::getDay() const {
    return day_;
  }
  size_t Student::getMonth() const {
    return month_;
  }
  size_t Student::getYear() const {
    return year_;
  }
  std::string Student::getAddress() const {
    return Person::getAddress();
  }
  std::string Student::getZipCode() const {
    return Person::getZipCode();
  }
  std::string Student::getCity() const {
    return Person::getCity();
  }
  std::string Student::getNationality() const {
    return Person::getNationality();
  }
  std::string Student::getIndexNumber() const {
    return indexNumber_;
  }
  std::string Student::getPesel() const {
    return Person::getPesel();
  }
  Gender Student::getGender() const {
    return Person::getGender();
  }

//setters
  void Student::setName(const std::string& name) {
    Person::setName(name);
  }
  void Student::setSurname(const std::string& surname) {
    Person::setSurname(surname);
  }
  void Student::setDay(const size_t day) {
    day_ = day;
  }
  void Student::setMonth(const size_t month) {
    month_ = month;
  }
  void Student::setYear(const size_t year) {
    year_ = year;
  }
  void Student::setAddress(const std::string& address) {
    Person::setAddress(address);
  }
  void Student::setZipCode(const std::string& zipcode) {
    Person::setZipCode(zipcode);
  }
  void Student::setCity(const std::string& city) {
    Person::setCity(city);
  }
  void Student::setNationality(const std::string& nationality) {
    Person::setNationality(nationality);
  }
  void Student::setIndexNumber(const std::string& indexNumber) {
    indexNumber_ = indexNumber;
  }
  void Student::setPesel(const std::string& pesel) {
    Person::setPesel(pesel);
  }
  void Student::setGender(Gender gender) {
    Person::setGender(gender);
  }

