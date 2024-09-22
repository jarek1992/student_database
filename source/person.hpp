#pragma once
#include <string>

enum class Gender {
  Male,
  Female,
  Unknown
};

class Person {
protected:
  std::string name_;
  std::string surname_;
  std::string address_;
  std::string zipcode_;
  std::string city_;
  std::string nationality_;
  std::string pesel_;
  Gender gender_;

//constructor 
public:
  Person(const std::string& name, const std::string& surname, const std::string& address, const std::string& zipcode, const std::string& city, const std::string& nationality, const std::string& pesel, Gender gender);
  virtual ~Person() = default;

//getters
  virtual std::string getName() const = 0;
  virtual std::string getSurname() const = 0;
  virtual std::string getAddress() const = 0;
  virtual std::string getZipCode() const = 0;
  virtual std::string getCity() const = 0;
  virtual std::string getNationality() const = 0;
  virtual std::string getPesel() const = 0;
  virtual Gender getGender() const = 0;

//setters
  virtual void setName(const std::string& name) = 0;
  virtual void setSurname(const std::string& surname) = 0;
  virtual void setAddress(const std::string& address) = 0;
  virtual void setZipCode(const std::string& zipcode) = 0;
  virtual void setCity(const std::string& city) = 0;
  virtual void setNationality(const std::string& nationality) = 0;
  virtual void setPesel(const std::string& pesel) = 0;
  virtual void setGender(Gender gender) = 0;  
};
