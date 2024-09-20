#pragma once
#include "person.hpp"

class Student : public Person {
private:
  size_t day_;
  size_t month_;
  size_t year_;
  std::string indexNumber_;

public:
  Student(const std::string& name, const std::string& surname, const size_t day, const size_t month, const size_t year, const std::string& address, const std::string& zipcode, const std::string& city, const std::string& nationality, const std::string& indexNumber, const std::string& pesel, Gender gender);
//getters
  std::string getName() const override;
  std::string getSurname() const override;
  size_t getDay() const;
  size_t getMonth() const;
  size_t getYear() const;
  std::string getAddress() const override;
  std::string getZipCode() const override;
  std::string getCity() const override;
  std::string getNationality() const override;
  std::string getIndexNumber() const;
  std::string getPesel() const override;
  Gender getGender() const override;
//setters
  void setName(const std::string& name) override;
  void setSurname(const std::string& surname) override;
  void setDay(const size_t day);
  void setMonth(const size_t month);
  void setYear(const size_t year);
  void setAddress(const std::string& address) override;
  void setZipCode(const std::string& zipcode) override;
  void setCity(const std::string& city) override;
  void setNationality(const std::string& nationality) override; 
  void setIndexNumber(const std::string& indexNumber);
  void setPesel(const std::string& pesel) override;
  void setGender(Gender gender) override;  

};

