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
  return name_;
}
std::string Employee::getSurname() const {
  return surname_;
}
std::string Employee::getAddress() const {
  return address_;
}
std::string Employee::getZipCode() const {
  return zipcode_;
}
std::string Employee::getCity() const {
  return city_;
}
std::string Employee::getNationality() const {
  return nationality_;
}
std::string Employee::getPesel() const {
  return pesel_;
}
Gender Employee::getGender() const {
  return gender_;
};
double Employee::getSalary() {
  return salary_;
}

// setters
void Employee::setEmployeeJob(const std::string &employeeJob) {
  employeeJob_ = employeeJob;
}
void Employee::setName(const std::string& name) {
  name_ = name;
}
void Employee::setSurname(const std::string& surname) {
  surname_ = surname;
}
void Employee::setAddress(const std::string& address) {
   address_ = address;
}
void Employee::setZipCode(const std::string& zipcode) {
  zipcode_ = zipcode;
}
void Employee::setCity(const std::string& city) {
  city_ = city;
}
void Employee::setNationality(const std::string& nationality) {
  nationality_ = nationality;
}
void Employee::setPesel(const std::string& pesel) {
  pesel_ = pesel;
}
void Employee::setGender(Gender gender) {
  gender_ = gender;
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