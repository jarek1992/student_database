#include "dataBase.hpp"
#include "student.hpp"
#include "peselValidator.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

bool isValidDay(const std::string& str) {
  for(char ch : str) {
    if(!std::isdigit(ch)) {
      return false;
    }
  }
  size_t day = std::stoul(str);
  return day >= 1 && day <= 31;
}
bool isValidMonth(const std::string& str) {
  for(char ch : str) {
    if(!std::isdigit(ch)) {
      return false;
    }
  }
  size_t month = std::stoul(str);
  return month >= 1 && month <= 12;
}
bool isValidYear(const std::string& str) {
  for(char ch : str) {
    if(!std::isdigit(ch)) {
      return false;
    }
  }
  size_t year = std::stoul(str);
  return year >= 1;
}

void StudentDataBase::addStudent(const Student &student) {
  studentMap[student.getIndexNumber()] = student;
}

void StudentDataBase::editStudentByIndexNumber(const std::string& indexNumber) {
  auto it = studentMap.find(indexNumber);
  if(it != studentMap.end()) {
    Student& student = it->second;
    
    // display current student data
    displayStudentByIndex(indexNumber);
    std::cout << "----------------------------------" <<std::endl;
    
    // variables declaration
    std::string name, surname, address, zipcode, city, nationality, pesel, genderC;

    // enter new student's data
    std::cout << "Update data: " << std::endl;
    std::cout << "enter new name(or press enter to keep current): ";
    std::getline(std::cin, name);
    if(!name.empty()) {
      student.setName(name);
    }
    
    std::cout << "enter new surname(or press enter to keep current): ";
    std::getline(std::cin, surname);
    if(!surname.empty()) {
      student.setSurname(surname);
    }
    
    std::cout << "enter new day of birth(or press enter to keep current): ";
    std::string newDay;
    std::getline(std::cin, newDay);
    if(!newDay.empty()) {
      if(isValidDay(newDay)) {
        student.setDay(std::stoul(newDay));
      } else {
        std::cout << "invalid day" << std::endl;
      }
    }
    
    std::cout << "enter new month of birth(or press enter to keep current): ";
    std::string newMonth;
    std::getline(std::cin, newMonth);
    if(!newMonth.empty()) {
      if(isValidMonth(newMonth)) {
        student.setMonth(std::stoul(newMonth));
      } else {
        std::cout << "invalid month" << std::endl;
      }
    }
    
    std::cout << "enter new year of birth(or press enter to keep current): ";
    std::string newYear;
    std::getline(std::cin, newYear);
    if(!newYear.empty()) {
      if(isValidYear(newYear)) {
        student.setYear(std::stoul(newYear));
      } else {
        std::cout << "invalid year" << std::endl;
      }
    }
    
    std::cout << "enter new address(or press enter to keep current): ";
    std::getline(std::cin, address);
    if(!address.empty()) {
      student.setAddress(address);
    }
    
    std::cout << "enter new zipcode(or press enter to keep current): ";
    std::getline(std::cin, zipcode);
    if(!zipcode.empty()) {
      student.setZipCode(zipcode);
    }
    
    std::cout << "enter new city(or press enter to keep current): ";
    std::getline(std::cin, city);
    if(!city.empty()) {
      student.setCity(city);
    }
    
    std::cout << "enter new nationality(or press enter to keep current): ";
    std::getline(std::cin, nationality);
    if(!nationality.empty()) {
      student.setNationality(nationality);
    }
    
    std::cout << "enter new PESEL(or press enter to keep current): ";
    while(true) {
      std::getline(std::cin, pesel);

      size_t currentDay = newDay.empty() ? student.getDay() :  std::stoul(newDay);
      size_t currentMonth = newMonth.empty() ? student.getMonth() : std::stoul(newMonth);
      size_t currentYear =  newYear.empty() ? student.getYear() : std::stoul(newYear);

      if(pesel.empty()) {
        if(newDay.empty() && newMonth.empty() && newYear.empty()) {
          break;
        }
        
        if(student.getPesel().empty() || Validator::validatePeselNumber(student.getPesel(), currentDay, currentMonth, currentYear)) {
          student.setDay(currentDay);
          student.setMonth(currentMonth);
          student.setYear(currentYear);
          break;
        } else {
          std::cout << "Incorrect PESEL. Set PESEL to empty? (Y/N): ";
          char choice;
          std::cin >> choice;
    
          if(choice == 'Y' || choice == 'y') {
            student.setPesel("");
            student.setDay(currentDay);
            student.setMonth(currentMonth);
            student.setYear(currentYear);
            break;
          } else if (choice == 'N' || choice == 'n') {
            std::cout << "enter a valid PESEL or press enter to skip." << std::endl;
          } else {
            std::cout << "Invalid choice. Enter Y/y or N/n to procced." << std::endl;
          }
        }
      } else {
        if(Validator::validatePeselNumber(pesel, currentDay, currentMonth, currentYear)) {
          student.setPesel(pesel);
          student.setDay(currentDay);
          student.setMonth(currentMonth);
          student.setYear(currentYear);
          break;
        } else {
          std::cout << "Incorrect PESEL. Try again or press Enter to skip." << std::endl;
        } 
      }
    }
    
    std::cout << "enter new gender(or press enter to keep current): ";
    std::getline(std::cin, genderC);
    if(genderC == "Male" || genderC == "male") {
      student.setGender(Gender::Male);
    } else if (genderC == "Female" || genderC == "female") {
      student.setGender(Gender::Female);
    } else if (genderC == "Unknown" || genderC == "unknown") {
      student.setGender(Gender::Unknown);
    } else if (genderC.empty()) {
    } else {
      std::cout << "default to unknown gender" << std::endl;
      student.setGender(Gender::Unknown);
    }
    
    std::cout << std::endl;
    std::cout << "data updated successfully!" << std::endl; 
  }
}

void StudentDataBase::displayStudentByIndex(const std::string &indexNumber) const {
  auto it = studentMap.find(indexNumber);
  if(it != studentMap.end()) {
    const Student& student = it->second;
    std::cout << "Name: " << student.getName() << std::endl;
    std::cout << "Surname: " << student.getSurname() << std::endl;
    std::cout << "Birth date: " << student.getDay() << "-" << student.getMonth() << "-" << student.getYear() << std::endl;
    std::cout << "Address: " << student.getAddress() << std::endl;
    std::cout << "ZipCode: " << student.getZipCode() << std::endl;
    std::cout << "City: " << student.getCity() << std::endl;
    std::cout << "Nationaltiy: " << student.getNationality() << std::endl;
    std::cout << "Index Number: " << student.getIndexNumber() << std::endl;
    std::cout << "Pesel: " << student.getPesel() << std::endl;
    std::cout << "Gender: ";
      switch(student.getGender()) {
        case Gender::Male: {
          std::cout << "Male";
          break;
        }
        case Gender::Female: {
          std::cout << "Female";
          break;
        }
        case Gender::Unknown: {
        default: {
          std::cout << "Unknown";
          break;
        }
        }
      }
    std::cout << std::endl;
  } else {
      std::cout << "student not found in database";
  }
}

void StudentDataBase::displayAllStudents() const {
  for (const auto& pair : studentMap) {
    displayStudentByIndex(pair.first);
    std::cout << "----------------------------------" <<std::endl;
  }
}

std::vector<Student> StudentDataBase::findStudentBySurname(const std::string &surname) const {
  std::vector<Student> result;
  std::string lowerSurname = surname;
  std::transform(lowerSurname.begin(), lowerSurname.end(), lowerSurname.begin(), ::tolower);
  
  for(const auto& pair : studentMap) {
    std::string lowerPairSurname = pair.second.getSurname();
    std::transform(lowerPairSurname.begin(), lowerPairSurname.end(), lowerPairSurname.begin(), ::tolower);
   
    if(lowerPairSurname == lowerSurname) {
      result.push_back(pair.second);
    }
  }
  return result;
}

Student StudentDataBase::findStudentByPesel(const std::string& pesel) const {
   for(const auto& pair : studentMap) {
     if(pair.second.getPesel() == pesel) {
       return pair.second;
     }
   }
  return Student();
}

void StudentDataBase::removeStudentByIndexNumber(const std::string &indexNumber) {
  auto it = studentMap.find(indexNumber);
  if(it != studentMap.end()) {
    studentMap.erase(it);
    std::cout << "student with index number " << indexNumber << " removed" << std::endl;   
  } else {
    std::cout << "student with index number " << indexNumber << " not found" << std::endl;
  } 
}

void StudentDataBase::sortAndDisplayByPesel() const {
  std::vector<std::pair<std::string, Student>> studentVector(studentMap.begin(), studentMap.end());
  std::sort(studentVector.begin(), studentVector.end(), [](const auto& a, const auto& b) {
    return std::stoll(a.second.getPesel())  < std::stoll(b.second.getPesel());
  });
  std::cout << std::endl;
  std::cout << "=========== Sorted by PESEL ===========" << std::endl;
  for(const auto& pair : studentVector) {
    displayStudentByIndex(pair.first);
    std::cout << "----------------------------------" << std::endl;
  }
}

void StudentDataBase::sortAndDisplayBySurname() const {
  std::vector<std::pair<std::string, Student>> studentVector(studentMap.begin(), studentMap.end());
  std::sort(studentVector.begin(), studentVector.end(), [](const auto& a, const auto& b) {
    return a.second.getSurname() < b.second.getSurname();
  });
  std::cout << std::endl;
  std::cout << "=========== Sorted by Surname ===========" << std::endl;
  for(const auto& pair : studentVector) {
    displayStudentByIndex(pair.first);
    std::cout << "----------------------------------" << std::endl;
  }
}