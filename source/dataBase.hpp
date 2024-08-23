#pragma once

#include "student.hpp"
#include "peselValidator.hpp"
#include <string>
#include <map>
#include <vector>

class StudentDataBase {
private:
  std::map<std::string, Student> studentMap;

public: 
  void addStudent(const Student& student);
  void editStudentByIndexNumber(const std::string& indexNumber);
  void displayStudentByIndex(const std::string& indexNumber) const;  
  void displayAllStudents() const;  
  std::vector<Student> findStudentBySurname(const std::string& surname) const;
  Student findStudentByPesel(const std::string& pesel) const;
  void removeStudentByIndexNumber(const std::string& indexNumber);
  void sortAndDisplayByPesel() const;
  void sortAndDisplayBySurname() const;
};



