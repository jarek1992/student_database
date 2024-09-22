#include "employee.hpp"

Employee::Employee(const std::string& employeeJob, const std::string& name, const std::string& surname, const std::string& address, const std::string& zipcode, const std::string& city, const std::string& nationality, const std::string& pesel, double salary, Gender gender)
  : Person(name, surname, address, zipcode, city, nationality, pesel, gender)
  , employeeJob_(employeeJob)
  , salary_(salary) 
{}

// getters
std::string Employee::getEmployeeJob() const {
  return employeeJob_;
}
std::string Employee::getName() const {
  return Person::getName();
}
std::string Employee::getSurname() const {
  return Person::getSurname();
}
std::string Employee::getAddress() const {
  return Person::getAddress();
}
std::string Employee::getZipCode() const {
  return Person::getZipCode();
}
std::string Employee::getCity() const {
  return Person::getCity();
}
std::string Employee::getNationality() const {
  return Person::getNationality();
}
std::string Employee::getPesel() const {
  return Person::getPesel();
}
Gender Employee::getGender() const {
  return Person::getGender();
};
double Employee::getSalary() {
  return salary_;
}

// setters
void Employee::setEmployeeJob(const std::string &employeeJob) {
  employeeJob_ = employeeJob;
}
void Employee::setName(const std::string& name) {
  Person::setName(name);
}
void Employee::setSurname(const std::string& surname) {
  Person::setSurname(surname);
}
void Employee::setAddress(const std::string& address) {
   Person::setAddress(address);
}
void Employee::setZipCode(const std::string& zipcode) {
  Person::setZipCode(zipcode);
}
void Employee::setCity(const std::string& city) {
  Person::setCity(city);
}
void Employee::setNationality(const std::string& nationality) {
  Person::setNationality(nationality);
}
void Employee::setPesel(const std::string& pesel) {
  Person::setPesel(pesel);
}
void Employee::setGender(Gender gender) {
  Person::setGender(gender);
}
void Employee::setSalary(double salary) { 
  if (salary >= 0) {
    salary_ = salary; 
  } else {
     throw std::invalid_argument("Salary cannot be negative");
  }
}
void Employee::promote(const std::string& newPosition) {
  employeeJob_ = newPosition;
  std::cout << getName() << " " << getSurname() << " has been promoted from " << getEmployeeJob() << " to " << employeeJob_ << std::endl;
}
void Employee::giveRaise(double percentage) {
  if(percentage > 0) {
    salary_ +=salary_ * (percentage / 100);
    std::cout << getName() << " " << getSurname() << " received a " << percentage << " % raise." << std::endl;
    std::cout << "New salary: " << salary_ << std::endl;
  } if (percentage == 0) {
    std::cout << "no raise to " << getName() << " " << getSurname() << "." << std::endl;
  } else {
    std::cout << "invalid percentage number for raise" << std::endl; 
  }
}