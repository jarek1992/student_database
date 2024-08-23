#pragma once
#include <string>

enum class Gender {
  Male,
  Female,
  Unknown
};

class Student {
private:
  std::string name_;
  std::string surname_;
  size_t day_;
  size_t month_;
  size_t year_;
  std::string address_;
  std::string zipcode_;
  std::string city_;
  std::string nationality_;
  std::string indexNumber_;
  std::string pesel_;
  Gender gender_;
//constructor 
public:
  Student() {};
  Student(const std::string& name, const std::string& surname, const size_t day, const size_t month, const size_t year, const std::string& address, const std::string& zipcode, const std::string& city, const std::string& nationality, const std::string& indexNumber, const std::string& pesel, Gender gender);
//getters
  std::string getName() const;
  std::string getSurname() const;
  size_t getDay() const;
  size_t getMonth() const;
  size_t getYear() const;
  std::string getAddress() const;
  std::string getZipCode() const;
  std::string getCity() const;
  std::string getNationality() const;
  std::string getIndexNumber() const;
  std::string getPesel() const;
  Gender getGender() const;
//setters
  void setName(const std::string& name);
  void setSurname(const std::string& surname);
  void setDay(const size_t day);
  void setMonth(const size_t month);
  void setYear(const size_t year);
  void setAddress(const std::string& address);
  void setZipCode(const std::string& zipcode);
  void setCity(const std::string& city);
  void setNationality(const std::string& nationality);
  void setIndexNumber(const std::string& indexNumber);
  void setPesel(const std::string& pesel);
  void setGender(Gender gender);  
};
