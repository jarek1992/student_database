#pragma once 
#include "person.hpp"

#include <iostream>
#include <string>

class Employee : public Person {
private:
  std::string employeeJob_;
  double salary_;

public:
  //constructor
  Employee(const std::string& employeeJob, const std::string& name, const std::string& surname, const std::string& address, const std::string& zipcode, const std::string& city, const std::string& nationality, const std::string& pesel, double salary, Gender gender);
  
  //getters
  std::string getEmployeeJob() const;
  std::string getName() const override;
  std::string getSurname() const override;
  std::string getAddress() const override;
  std::string getZipCode() const override;
  std::string getCity() const override;
  std::string getNationality() const override;
  std::string getPesel() const override;
  Gender getGender() const override;
  double getSalary() const;
  
  //setters
  void setEmployeeJob(const std::string& employeeJob);
  void setName(const std::string& name) override;
  void setSurname(const std::string& surname) override;
  void setAddress(const std::string& address) override;
  void setZipCode(const std::string& zipcode) override;
  void setCity(const std::string& city) override;
  void setNationality(const std::string& nationality) override; 
  void setPesel(const std::string& pesel) override;
  void setGender(Gender gender) override;  
  void setSalary(double salary);

  //additional methods specific for employee
  void promote(const std::string& newPosition);
  void giveRaise(double percentage);
};