#include "dataBase.hpp"
#include "peselValidator.hpp"
#include "student.hpp"
#include "employee.hpp"
#include "person.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

bool isValidDay(const std::string& str) {
    for (char ch : str) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }
    size_t day = std::stoul(str);
    return day >= 1 && day <= 31;
}
bool isValidMonth(const std::string& str) {
    for (char ch : str) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }
    size_t month = std::stoul(str);
    return month >= 1 && month <= 12;
}
bool isValidYear(const std::string& str) {
    for (char ch : str) {
        if (!std::isdigit(ch)) {
            return false;
        }
    }
    size_t year = std::stoul(str);
    return year >= 1;
}
std::string toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}
bool isNumeric(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

void UniversityDataBase::addStudent(const std::shared_ptr<Student>& student) {
    personMap[student->getIndexNumber()] = student;
}

void UniversityDataBase::editStudentByIndexNumber(const std::string& indexNumber) {
    auto it = personMap.find(indexNumber);
    if (it != personMap.end()) {
        auto student = std::dynamic_pointer_cast<Student>(it->second);
        // display current student data
        if (student) {
            displayPersonByIndex(indexNumber);
            std::cout << "----------------------------------" << std::endl;
            // variables declaration
            std::string name, surname, address, zipcode, city, nationality, pesel, genderC;
            size_t day = student->getDay();
            size_t month = student->getMonth();
            size_t year = student->getYear();
            // enter new student's data
            std::cout << "Update data: " << std::endl;
            std::cout << "enter new name(or press enter to keep current): ";
            std::getline(std::cin, name);
            if (!name.empty()) {
                student->setName(name);
            }
            std::cout << "enter new surname(or press enter to keep current): ";
            std::getline(std::cin, surname);
            if (!surname.empty()) {
                student->setSurname(surname);
            }
            std::cout << "enter new day of birth(or press enter to keep current): ";
            std::string newDay;
            std::getline(std::cin, newDay);
            if (!newDay.empty() && isValidDay(newDay)) {
                day = std::stoul(newDay);
            } else {
                std::cout << " skipping/invalid day" << std::endl;
            }
            std::cout << "enter new month of birth(or press enter to keep current): ";
            std::string newMonth;
            std::getline(std::cin, newMonth);
            if (!newMonth.empty() && isValidMonth(newMonth)) {
                month = std::stoul(newMonth);
            } else {
                std::cout << " skipping/invalid month" << std::endl;
            }
            std::cout << "enter new year of birth(or press enter to keep current): ";
            std::string newYear;
            std::getline(std::cin, newYear);
            if (!newYear.empty() && isValidYear(newYear)) {
                year = std::stoul(newYear);
            } else {
                std::cout << " skipping/invalid year" << std::endl;
            }
            std::cout << "enter new address(or press enter to keep current): ";
            std::getline(std::cin, address);
            if (!address.empty()) {
                student->setAddress(address);
            }
            std::cout << "enter new zipcode(or press enter to keep current): ";
            std::getline(std::cin, zipcode);
            if (!zipcode.empty()) {
                student->setZipCode(zipcode);
            }
            std::cout << "enter new city(or press enter to keep current): ";
            std::getline(std::cin, city);
            if (!city.empty()) {
                student->setCity(city);
            }
            std::cout << "enter new nationality(or press enter to keep current): ";
            std::getline(std::cin, nationality);
            if (!nationality.empty()) {
                student->setNationality(nationality);
            }
            std::cout << "enter new PESEL(or press enter to keep current): ";
            while (true) {
                std::getline(std::cin, pesel);
                if (pesel.empty()) {
                    if (student->getPesel().empty() || Validator::validatePeselNumber(student->getPesel(), day, month, year)) {
                        student->setDay(day);
                        student->setMonth(month);
                        student->setYear(year);
                        break;
                    } else {
                        std::cout << "Incorrect PESEL. Set PESEL to empty? (Y/N): ";
                        char choice;
                        std::cin >> choice;
                        if (choice == 'Y' || choice == 'y') {
                            student->setPesel("");
                            student->setDay(day);
                            student->setMonth(month);
                            student->setYear(year);
                            break;
                        } else if (choice == 'N' || choice == 'n') {
                            std::cout << "enter a valid PESEL or press enter to skip." << std::endl;
                        } else {
                            std::cout << "Invalid choice. Enter Y/y or N/n to procced." << std::endl;
                        }
                    }
                } else {
                    if (Validator::validatePeselNumber(pesel, day, month, year)) {
                        student->setPesel(pesel);
                        student->setDay(day);
                        student->setMonth(month);
                        student->setYear(year);
                        break;
                    } else {
                        std::cout << "Incorrect PESEL. Try again or press Enter to skip." << std::endl;
                    }
                }
            }
            std::cout << "enter new gender(or press enter to keep current): ";
                std::getline(std::cin, genderC);
                if (genderC == "Male" || genderC == "male") {
                    student->setGender(Gender::Male);
                } else if (genderC == "Female" || genderC == "female") {
                    student->setGender(Gender::Female);
                } else if (genderC == "Unknown" || genderC == "unknown") {
                    student->setGender(Gender::Unknown);
                } else if (genderC.empty()) {
                } else {
                    std::cout << "default to unknown gender" << std::endl;
                    student->setGender(Gender::Unknown);
                }
                std::cout << std::endl;
                std::cout << "data updated successfully!" << std::endl;
            } else {
                std::cout << "student not found!" << std::endl;
            }
        } else {
            std::cout << "student with ID " << indexNumber << " not found" << std::endl;
        }   
}

void UniversityDataBase::displayPersonByIndex(const std::string& pesel) const {
    auto it = personMap.find(pesel);
    if (it != personMap.end()) {
        //common datas for students and employees
        std::cout << "Name: " << it->second->getName() << std::endl;
        std::cout << "Surname: " << it->second->getSurname() << std::endl;
        std::cout << "Address: " << it->second->getAddress() << std::endl;
        std::cout << "ZipCode: " << it->second->getZipCode() << std::endl;
        std::cout << "City: " << it->second->getCity() << std::endl;
        std::cout << "Nationality: " << it->second->getNationality() << std::endl;
        std::cout << "Pesel: " << it->second->getPesel() << std::endl;
        std::cout << "Gender: ";
        switch (it->second->getGender()) {
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
        //specific only for students and employess
         if (auto student = std::dynamic_pointer_cast<Student>(it->second)) {
             std::cout << "Birth date: " << student->getDay() << "-" << student->getMonth() << "-" << student->getYear() << std::endl;
             std::cout << "Index Number: " << student->getIndexNumber() << std::endl;  
         } else if (auto employee = std::dynamic_pointer_cast<Employee>(it->second)) {
             std::cout << "Employee Position: " << employee->getEmployeeJob() << std::endl;
             std::cout << "Salary: " << employee->getSalary() << "€" << std::endl;
         }
            std::cout << std::endl;
        } else {
            std::cout << "person not found in database";
            std::cout << std::endl;
        }
    }

void UniversityDataBase::addEmployee(const std::shared_ptr<Employee>& employee) {
    personMap[employee->getPesel()] = employee;
}

void UniversityDataBase::editEmployeeBySurname(const std::string& surname) {
    bool found = false;
    // convert the input surname to lowercase for case-insensitive comparision
    std::string lowerSurname = surname;
    std::transform(lowerSurname.begin(), lowerSurname.end(), lowerSurname.begin(), ::tolower);

    for (const auto& pair : personMap) {
        auto employee = std::dynamic_pointer_cast<Employee>(pair.second);
        if (employee) {
            std::string employeeSurname = employee->getSurname();
            std::transform(employeeSurname.begin(), employeeSurname.end(), employeeSurname.begin(), ::tolower);

            if (employeeSurname == lowerSurname) {
                found = true;

                std::cout << std::endl;
                std::cout << "=========== EMPLOYEE: " << surname << " ===========" << std::endl;
                displayPersonByIndex(employee->getPesel());
                std::cout << "----------------------------------" << std::endl;

                std::string newPosition;
                std::string newAddress;
                std::string newZipCode;
                std::string newCity;
                double percentage;

                //promote employee
                std::cout << "enter new employee position(or press enter to keep current): ";
                std::getline(std::cin, newPosition);
                if (!newPosition.empty()) {
                    employee->promote(newPosition);
                }
                //get new details for employee from user 
                std::cout << "enter new address(or press enter to keep current): ";
                std::getline(std::cin, newAddress);
                if (!newAddress.empty()) {
                    employee->setAddress(newAddress);
                }
                std::cout << "enter new zip code(or press enter to keep current): ";
                std::getline(std::cin, newZipCode);
                if (!newZipCode.empty()) {
                    employee->setZipCode(newZipCode);
                }
                std::cout << "enter new city(or press enter to keep current): ";
                std::getline(std::cin, newCity);
                if (!newCity.empty()) {
                    employee->setCity(newCity);
                }
                std::cout << "enter salary raise 0-100%: ";
                std::cin >> percentage;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                if (percentage >= 0) {
                    employee->giveRaise(percentage);
                } else if (percentage < 0 && percentage > 100.0) {
                    std::cout << "Invalid salary input. Salary not updated" << std::endl;
                }
                std::cout << "Employee " << surname << " details updated successfully!" << std::endl;
                
                //edit further if other employee with the same surname
                char choice;
                std::cout << "Do you want to edit another employee with the same surname if exists in database? (Y/N): ";
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (choice == 'N' || choice == 'n') {
                    break;
                }
            }            
        }
    } 
    if(!found) {
        std::cout << "Employee with surname " << surname << " not found" << std::endl;
    }
}

void UniversityDataBase::displayAllPersons() const {
    //display students list
    std::cout << "STUDENTS LIST: " << std::endl;
    std::cout << std::endl;
    for (const auto& pair : personMap) {
        if (std::dynamic_pointer_cast<Student>(pair.second)) {
            //display only student
            displayPersonByIndex(pair.first);
            std::cout << "----------------------------------" << std::endl;
        }
    }
    //display employees list
    std::cout << "EMPLOYEES LIST: " << std::endl;
    std::cout << std::endl;
    for (const auto& pair : personMap) {
        if (std::dynamic_pointer_cast<Employee>(pair.second)) {
            //display only employees
            displayPersonByIndex(pair.first);
            std::cout << "----------------------------------" << std::endl;
        }
    }
}

std::vector<std::shared_ptr<Person>> UniversityDataBase::findPersonBySurname(const std::string& surname) const {
    std::vector<std::shared_ptr<Person>> result;
    std::string lowerSurname = surname;
    std::transform(lowerSurname.begin(), lowerSurname.end(), lowerSurname.begin(), ::tolower);

    for (const auto& pair : personMap) {
        std::string personSurname = pair.second->getSurname();
        //transform only once per comparison
        std::string lowerPersonSurname = personSurname;
        std::transform(lowerPersonSurname.begin(), lowerPersonSurname.end(), lowerPersonSurname.begin(), ::tolower);

        if (lowerPersonSurname == lowerSurname) {
            result.push_back(pair.second);
        }
    }
    return result;
}

std::shared_ptr<Person> UniversityDataBase::findPersonByPesel(const std::string& pesel) const {
    //iterating over all elements in personMap
    for (const auto& pair : personMap) {
        if (pair.second->getPesel() == pesel) {
            return pair.second;
        }
    }
    return nullptr; 
}

void UniversityDataBase::removeStudentByIndexNumber(const std::string& indexNumber) {
    auto it = std::find_if(personMap.begin(), personMap.end(), 
        [&indexNumber](const std::pair<std::string, std::shared_ptr<Person>>& pair) {
           auto student = std::dynamic_pointer_cast<Student>(pair.second);
            return student && student->getIndexNumber() == indexNumber;
        });

    if (it != personMap.end()) {
        //capture student details before removal
        auto student = std::dynamic_pointer_cast<Student>(it->second);
        //remove the student from the map
        personMap.erase(it);
        std::cout << "student with index number " << indexNumber << " removed" << std::endl;
        std::cout << "name: " << student->getName() << " surname: " << student->getSurname() << std::endl;
    } else {
        std::cout << "student with index number " << indexNumber << " not found" << std::endl;
    }
}

void UniversityDataBase::removeEmployeeByPesel(const std::string& pesel) {
    auto it = personMap.find(pesel);
    if (it!= personMap.end()) {
        auto employee = std::dynamic_pointer_cast<Employee>(it->second);
        if (employee) {
            personMap.erase(it);
            std::cout << "Employee with PESEL " << pesel << " removed" << std::endl;
            std::cout << "name: " << employee->getName() << " surname: " << employee->getSurname() << std::endl;
        } else {
            std::cout << "Employee with PESEL "  << pesel << " is not an employee" << std::endl;
        }
    } else {
        std::cout << "Employee with PESEL "  << pesel << " not found" << std::endl;   
    }
}

void UniversityDataBase::sortAndDisplayByPesel() const {
    std::vector<std::pair<std::string, std::shared_ptr<Person>>> personVector(personMap.begin(), personMap.end());
    //sort the vector by PESEL. Non numeric like ID0 will be considered "less than" numeric
    std::sort(personVector.begin(), personVector.end(), [](const auto& a, const auto& b) {
        std::string peselA = a.second->getPesel();
        std::string peselB = b.second->getPesel();

        bool isPeselANumeric = isNumeric(peselA);
        bool isPeselBNumeric = isNumeric(peselB);
        //comparison for numeric PESELs
        if (isPeselANumeric && isPeselBNumeric) {
            return std::stoll(peselA) < std::stoll(peselB);
        //comparison for non-numeric PESELs
        } else if (!isPeselANumeric && !isPeselBNumeric) {
            return peselA < peselB;
        //non-numeric PESELs go before numeric ones
        } else {
            return isPeselANumeric;
        }  
    }); 
    std::cout << std::endl;
    std::cout << "=========== Sorted by PESEL ===========" << std::endl;
    
    for (const auto& pair : personVector) {
        displayPersonByIndex(pair.first);
        std::cout << "----------------------------------" << std::endl;
    }
}

void UniversityDataBase::sortAndDisplayBySurname() const {
    std::vector<std::pair<std::string, std::shared_ptr<Person>>> personVector(personMap.begin(), personMap.end());
    
    // sort the vector by surname
    std::sort(personVector.begin(), personVector.end(), [](const auto& a, const auto& b) {
        return toLowerCase(a.second->getSurname()) < toLowerCase(b.second->getSurname());
    });
    
    std::cout << std::endl;
    std::cout << "=========== Sorted by Surname ===========" << std::endl;
    
    for (const auto& pair : personVector) {
        displayPersonByIndex(pair.first);
        std::cout << "----------------------------------" << std::endl;
    }
}

void UniversityDataBase::saveToFile(const std::string& university_DataBase) const {
    std::fstream dataBase(university_DataBase, std::ios::out);

    if (!dataBase.is_open()) {
        throw std::runtime_error("could not open file for writing");
    }

    for (const auto& pair : personMap) {
        std::shared_ptr<Student> student = std::dynamic_pointer_cast<Student>(pair.second);
        std::shared_ptr<Employee> employee = std::dynamic_pointer_cast<Employee>(pair.second);

        if (student) {
            dataBase << "Student\n";
            dataBase << "Name: " << student->getName() << "\n"
                     << "Surname: " << student->getSurname() << "\n"
                     << "Address: " << student->getAddress() << "\n"
                     << "ZipCode: " << student->getZipCode() << "\n"
                     << "City: " << student->getCity() << "\n"
                     << "Nationality: " << student->getNationality() << "\n"
                     << "Pesel: " << student->getPesel() << "\n"
                     << "Gender: " << (student->getGender() == Gender::Male ? "Male" : student->getGender() == Gender::Female ? "Female" : "Unknown") << "\n"
                     << "Birth date: " << student->getDay() << "-" << student->getMonth() << "-" << student->getYear() << "\n"
                     << "Index Number: " << student->getIndexNumber() << "\n"
                     << "----------------------------------" << "\n";
        } else if (employee) {
            dataBase << "Employee\n";
            dataBase << "Name: " << employee->getName() << "\n"
                     << "Surname: " << employee->getSurname() << "\n"
                     << "Address: " << employee->getAddress() << "\n"
                     << "ZipCode: " << employee->getZipCode() << "\n"
                     << "City: " << employee->getCity() << "\n"
                     << "Nationality: " << employee->getNationality() << "\n"
                     << "Pesel: " << employee->getPesel() << "\n"
                     << "Gender: " << (employee->getGender() == Gender::Male ? "Male" : employee->getGender() == Gender::Female ? "Female" : "Unknown") << "\n"
                     << "Employee Position: " << employee->getEmployeeJob() << "\n"
                     << "Salary: " << employee->getSalary() << "\n"
                     << "----------------------------------" << "\n";
        }
    }
    std::cout << "Database saved to " << university_DataBase << std::endl;
    std::cout << std::endl;
}

void UniversityDataBase::loadFromFile(const std::string& university_DataBase) {
    std::fstream dataBase(university_DataBase, std::ios::in);

    if (!dataBase.is_open()) {
        throw std::runtime_error("could not open file to load");
    }

    personMap.clear();
    std::string line;
    std::string name, surname, address, zipcode, city, nationality, indexNumber, pesel, genderStr, employeeJob;
    size_t day = 0, month = 0, year = 0;
    Gender gender = Gender::Unknown;
    double salary = 0.0;
    bool isEmployee = false;

    while (std::getline(dataBase, line)) {
        if (line == "Student") {
            isEmployee = false;
        } else if (line == "Employee") {
            isEmployee = true;
        } else if (line.empty() || line == "----------------------------------") {
            continue;
        }

        //parse fields for both students and employees
        if (line.find("Name: ") == 0) {
            name = line.substr(6);
        } else if (line.find("Surname: ") == 0) {
            surname = line.substr(9);
        } else if (line.find("Address: ") == 0) {
            address = line.substr(9);
        } else if (line.find("Zipcode: ") == 0) {
            zipcode = line.substr(9);
        } else if (line.find("City: ") == 0) {
            city = line.substr(6);
        } else if (line.find("Nationality: ") == 0) {
            nationality = line.substr(13);
        } else if (line.find("Pesel: ") == 0) {
            pesel = line.substr(7);
        } else if (line.find("Gender: ") == 0) {
            genderStr = line.substr(8);
            if (genderStr == "Male") {
                gender = Gender::Male;
            } else if (genderStr == "Female") {
                gender = Gender::Female;
            } else {
                gender = Gender::Unknown;
            }
        } 
        //parse specific fields for employees or students
        if (isEmployee) {
            if (line.find("Employee Position: ") == 0) {
                employeeJob = line.substr(18); 
            } else if (line.find("Salary: ") == 0) {
            salary = std::stod(line.substr(8));
            }
        } else {
            if (line.find("Birth date: ") == 0) {
                std::sscanf(line.c_str(), "Birth date: %zu-%zu-%zu", &day, &month, &year);
            } else if (line.find("Index Number: ") == 0) {
                indexNumber = line.substr(14);
            }
        }
        //create either a student or employee
        if (line == "----------------------------------") {
            if (isEmployee) {
                auto employee = std::make_shared<Employee>(employeeJob, name, surname, address, zipcode, city, nationality, pesel, salary, gender);
                personMap[pesel] = employee;
            } else {
                auto student = std::make_shared<Student>(name, surname, day, month, year, address, zipcode, city, nationality, indexNumber, pesel, gender);
                personMap[indexNumber] = student;
            }
            // Reset values for next record
            name.clear();
            surname.clear();
            address.clear();
            zipcode.clear();
            city.clear();
            nationality.clear();
            indexNumber.clear();
            pesel.clear();
            employeeJob.clear();
            genderStr.clear();
            day = month = year = 0;
            salary = 0.0;
            gender = Gender::Unknown;
            isEmployee = false;
        }
    }
    std::cout << "Database loaded from: " << university_DataBase << std::endl;
    std::cout << std::endl;
}

std::string UniversityDataBase::generateUniqueKey() {
    static int uniqueIdCounter = 0;
    std::string uniqueKey;
    //loop until found a truly unique key
    do {
        uniqueKey = "ID" + std::to_string(uniqueIdCounter);
        uniqueIdCounter++;
    } while (personMap.find(uniqueKey) != personMap.end());
    return uniqueKey;
}