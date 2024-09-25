#pragma once

#include "peselValidator.hpp"
#include "student.hpp"
#include "employee.hpp"
#include "person.hpp"
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>

class UniversityDataBase {
private:
    std::unordered_map<std::string, std::shared_ptr<Person>> personMap;

public:
    void addStudent(const std::shared_ptr<Student>& student);
    void editStudentByIndexNumber(const std::string& indexNumber);
    void displayPersonByIndex(const std::string& pesel) const;
    void addEmployee(const std::shared_ptr<Employee>& employee);
    void editEmployeeBySurname(const std::string& surname);
    void displayAllPersons() const;
    std::vector<std::shared_ptr<Person>> findPersonBySurname(const std::string& surname) const;
    std::shared_ptr<Person> findPersonByPesel(const std::string& pesel) const;
    void removeStudentByIndexNumber(const std::string& indexNumber);
    void removeEmployeeByPesel(const std::string& pesel);
    void sortAndDisplayByPesel() const;
    void sortAndDisplayBySurname() const;
    void saveToFile(const std::string& university_DataBase) const;
    void loadFromFile(const std::string& university_DataBase);
    std::string generateUniqueKey();
};
