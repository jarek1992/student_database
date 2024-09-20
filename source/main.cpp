#include "dataBase.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <regex>

void displayMenu() {
    std::cout << "============== Menu ==============" << std::endl;
    std::cout << "1 - Add a student" << std::endl;
    std::cout << "2 - Edit a student" << std::endl;
    std::cout << "3 - Display a student by index number" << std::endl;
    std::cout << "4 - Add an employee" << std::endl;
    std::cout << "5 - Edit an employee" << std::endl;
    std::cout << "6 - Display database" << std::endl;
    std::cout << "7 - Search by surname" << std::endl;
    std::cout << "8 - Search by PESEL" << std::endl;
    std::cout << "9 - Remove a student" << std::endl;
    std::cout << "10 - Remove an employee" << std::endl;
    std::cout << "11 - Sort by PESEL" << std::endl;
    std::cout << "12 - Sort by surname" << std::endl;
    std::cout << "13 - Save to file" << std::endl;
    std::cout << "14 - Load from file" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    std::cout << "Choose an option: ";
}

bool isValidDay(size_t day) {
    return day >= 1 && day <= 31;
}
bool isValidMonth(size_t month) {
    return month >= 1 && month <= 12;
}
bool isValidYear(size_t year) {
    return year >= 1;
}
bool isValidIndexNumber(const std::string& indexNumber) {
    std::regex indexPattern("^[0-9]{6}[A-Za-z]{2}$");
    return std::regex_match(indexNumber, indexPattern);
}
bool isNumber(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    UniversityDataBase db;
    int choice;
    // std::string students_DataBase;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        //add a student
        case 1: {
            std::string name;
            std::string surname;
            size_t day = 0;
            size_t month = 0;
            size_t year = 0;
            std::string address;
            std::string zipcode;
            std::string city;
            std::string nationality;
            std::string indexNumber;
            std::string pesel;
            std::string genderC;
            Gender gender;

            std::cout << std::endl;
            std::cout << "=========== ADD NEW STUDENT ===========" << std::endl;
            //get student name and surname
            std::cout << "enter a name: ";
            std::getline(std::cin, name);

            std::cout << "enter a surname: ";
            std::getline(std::cin, surname);

            //day of birth
            std::cout << "date of birth: " << std::endl;
            std::cout << " - enter a day(1-31) or press enter to skip: ";
            while (true) {
                std::string inputDay;
                std::getline(std::cin, inputDay);
                if (inputDay.empty()) {
                    day = 0;
                    break;
                } else if (isNumber(inputDay)) {
                    day = std::stoul(inputDay);
                    if (isValidDay(day)) {
                        break;
                    } else {
                        std::cout << " - day out of range (1-31). Enter new day or press enter to skip: ";
                    }
                } else {
                    std::cout << " - day out of range (1-31). Enter new day or press enter to skip: ";
                }
            }
            std::cout << std::endl;
            // month of birth
            std::cout << " - enter a month(1-12) or press enter to skip: ";
            while (true) {
                std::string inputMonth;
                std::getline(std::cin, inputMonth);
                if (inputMonth.empty()) {
                    month = 0;
                    break;
                } else if (isNumber(inputMonth)) {
                    month = std::stoul(inputMonth);
                    if (isValidMonth(month)) {
                        break;
                    } else {
                        std::cout << " - month out of range (1-12). Enter new month or press enter to skip: ";
                    }
                } else {
                    std::cout << " - month out of range (1-12). Enter new month or press enter to skip: ";
                }
            }
            std::cout << std::endl;
            // year of birth
            std::cout << " - enter a year(e.g. 1994) or press enter to skip: ";
            while (true) {
                std::string inputYear;
                std::getline(std::cin, inputYear);

                if (inputYear.empty()) {
                    year = 0;
                    break;
                } else if (isNumber(inputYear)) {
                    year = std::stoul(inputYear);
                    if (isValidYear(year)) {
                        break;
                    } else {
                        std::cout << " - year invalid. Enter new year or press enter to skip: ";
                    }
                } else {
                    std::cout << " - year invalid. Enter new year or press enter to skip: ";
                }
            }
            // get student address, zipcode, city, and nationality
            std::cout << "enter an address: ";
            std::getline(std::cin, address);

            std::cout << "enter a zipcode: ";
            std::getline(std::cin, zipcode);

            std::cout << "enter a city: ";
            std::getline(std::cin, city);

            std::cout << "enter a nationality: ";
            std::getline(std::cin, nationality);

            std::cout << "REQUIRED - enter index number(e.g.111111Fg): " ;
            while (!(std::cin >> indexNumber) || !isValidIndexNumber(indexNumber)) {
                if (!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Invalid index number. Required 6 digits and and two letters. Try again?(Y/N): ";
                char tryAgain;
                std::cin >> tryAgain;
                if (tryAgain != 'y' && tryAgain != 'Y') {
                    break;
                }
                std::cout << "enter index number(e.g.111111Fg): ";
            }
            //get student PESEL
            std::cout << "enter student's PESEL: ";
            std::cin.ignore();
            while (true) {
                std::getline(std::cin, pesel);
                if (pesel.empty()) {
                    break;
                }
                if (Validator::validatePeselNumber(pesel, day, month, year)) {
                    break;
                } else {
                    std::cout << "Incorrect PESEL. Try again or press enter to skip. " << std::endl;
                }
            }
            //get student gender 
            std::cout << "enter a gender(Male/Female): ";
            std::getline(std::cin, genderC);
            if (genderC == "Male" || genderC == "male") {
                gender = Gender::Male;
            } else if (genderC == "Female" || genderC == "female") {
                gender = Gender::Female;
            } else {
                std::cout << "unknown gender input" << std::endl;
                gender = Gender::Unknown;
            }
            //add student to database
            db.addStudent(std::make_shared<Student>(name, surname, day, month, year, address, zipcode,
                                  city, nationality, indexNumber, pesel, gender));
            std::cout << std::endl;
            std::cout << "student added successfully to database!" << std::endl;
            std::cout << std::endl;
            break;
        }
        //edit student by index number
        case 2: {
            std::string indexNumber;
            std::cout << "enter index number(e.g.111111Fg): ";
            std::getline(std::cin, indexNumber);
            if (!isValidIndexNumber(indexNumber)) {
                std::cout << "invalid index number" << std::endl;
                std::cout << std::endl;
                break;
            }
            std::cout << std::endl;
            std::cout << "=========== STUDENT ID: " << indexNumber << " ===========" << std::endl;
            db.editStudentByIndexNumber(indexNumber);
            std::cout << std::endl;
            break;
        }
        //display student by index number
        case 3: {
            std::string indexNumber;
            std::cout << "enter student's index number: ";
            std::getline(std::cin, indexNumber);
            std::cout << std::endl;
            std::cout << "=========== STUDENT ID: " << indexNumber << " ===========" << std::endl;
            db.displayPersonByIndex(indexNumber);
            std::cout << std::endl;
            break;
        }
        //add an employee
        case 4: {
            std::string employeeJob;
            std::string name;
            std::string surname;
            std::string address;
            std::string zipcode;
            std::string city;
            std::string nationality;
            std::string pesel;
            double salary = 0.0;
            std::string genderC;
            Gender gender;

            std::cout << std::endl;
            std::cout << "=========== ADD NEW EMPLOYEE ===========" << std::endl;

            //get employee job position
            std::cout << "enter an employee's job: ";
            std::getline(std::cin, employeeJob);
            
            //get employee name and surname
            std::cout << "enter a name: ";
            std::getline(std::cin, name);
            std::cout << "enter a surname: ";
            std::getline(std::cin, surname);
            
            // get employee address, zipcode, city, and nationality
            std::cout << "enter an address: ";
            std::getline(std::cin, address);
            std::cout << "enter a zipcode: ";
            std::getline(std::cin, zipcode);
            std::cout << "enter a city: ";
            std::getline(std::cin, city);
            std::cout << "enter a nationality: ";
            std::getline(std::cin, nationality);
            
            //get employee PESEL
            std::cout << "enter employee's PESEL: ";
            std::getline(std::cin, pesel);
            
            //get employee salary
            std::cout << "enter employee's salary: ";
            while (!(std::cin >> salary) || salary < 0.0) {
                std::cout << "Invalid input. Salary cannot be negative number. Try again: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cin.ignore();
            
            //get student gender 
            std::cout << "enter a gender(Male/Female): ";
            std::getline(std::cin, genderC);
            if (genderC == "Male" || genderC == "male") {
                gender = Gender::Male;
            } else if (genderC == "Female" || genderC == "female") {
                gender = Gender::Female;
            } else {
                std::cout << "unknown gender input" << std::endl;
                gender = Gender::Unknown;
            }
            
            //add employee to database
            db.addEmployee(std::make_shared<Employee>(employeeJob, name, surname, address, zipcode, city, nationality, pesel, salary, gender));
            std::cout << std::endl;
            std::cout << "Employee added successfully to database!" << std::endl;
            std::cout << "Employee Details: " << name << ", Surname: " << surname << ", Job: " << employeeJob << std::endl; // Added confirmation
            std::cout << std::endl;
            break;
        }
        //edit employee
        case 5 : {
            std::string surname;
            std::cout << "enter the surname of the employye: ";
            std::getline(std::cin, surname);

            if (surname.empty()) {
                std::cout << "Surname cannot be empty." << std::endl;
                break;
            }
            
            db.editEmployeeBySurname(surname);
            std::cout << "Employee with surname '" << surname << "' edited successfully!" << std::endl;
            break;
        }
        //display database
        case 6: {
            std::cout << std::endl;
            std::cout << "=========== DATABASE ===========" << std::endl;
            db.displayAllPersons();
            std::cout << std::endl;
            break;
        }
        //search by surname
        case 7: {
            std::string surname;
            std::vector<std::shared_ptr<Person>> results;
            bool found = false;

            do {
                std::cout << "enter the surname: ";
                std::getline(std::cin, surname);

                std::string lowerSurname = surname;
                std::transform(lowerSurname.begin(), lowerSurname.end(), lowerSurname.begin(), ::tolower);

                results = db.findPersonBySurname(lowerSurname);
                std::cout << std::endl;

                if (results.empty()) {
                    std::cout << "Person with surname " << surname << " not found. Try again? (Y/N): ";
                    char tryAgain;
                    std::cin >> tryAgain;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (tryAgain != 'Y' && tryAgain != 'y') {
                        std::cout << "Exit searching " << std::endl;
                        break;
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "=========== PERSON " << surname << " ===========" << std::endl;
                    for (const auto& person : results) {
                        auto student = std::dynamic_pointer_cast<Student>(person);
                        if (student) {
                            db.displayPersonByIndex(student->getPesel());
                            std::cout << std::endl;
                        } else {
                            std::cout << "Found an employee with the same surname, skipping..." << std::endl;
                        }
                    }
                    found = true;
                }
            } while (!found);
            break;
        }
        //search by PESEL
        case 8: {
            std::string pesel;
            std::cout << "enter a PESEL: ";
            std::getline(std::cin, pesel);
            
            std::shared_ptr<Person> foundPerson = db.findPersonByPesel(pesel);

            if (!foundPerson) {
                std::cout << "Person with PESEL: " << pesel << " not found" << std::endl;
                std::cout << std::endl;
            } else {
                std::cout << std::endl;

                //check if foundPerson is a student
                auto student = std::dynamic_pointer_cast<Student>(foundPerson);
                if (student) {
                    std::cout << "=========== STUDENT PESEL:" << pesel << " ===========" << std::endl;
                    db.displayPersonByIndex(student->getPesel());
                } else {
                    //if foundPerson is an employee
                    auto employee = std::dynamic_pointer_cast<Employee>(foundPerson);
                    if (employee) {
                        std::cout << "=========== EMPLOYEE PESEL:" << pesel << " ===========" << std::endl;
                        db.displayPersonByIndex(student->getPesel());
                    } else {
                        std::cout << "Person with PESEL: " << pesel << " is neither a student nor an employee." << std::endl;
                    } 
                }
                std::cout << std::endl;
            }
            break;
        }
        //remove student by index number
        case 9: {
            std::string indexNumber;
            std::cout << "enter student's index number: ";
            std::getline(std::cin, indexNumber);
            db.removeStudentByIndexNumber(indexNumber);
            std::cout << std::endl;
            break;
        }
        //remove employee by PESEL
        case 10: {
            std::string pesel;
            std::cout << "enter employee's PESEL: ";
            std::getline(std::cin, pesel);
            db.removeEmployeeByPesel(pesel);
            std::cout << std::endl;
            break;
        }
        //sort by PESEL
        case 11: {
            db.sortAndDisplayByPesel();
            std::cout << "students sorted by pesel's number" << std::endl;
            std::cout << std::endl;
            break;
        }
        //sort by surname
        case 12: {
            db.sortAndDisplayBySurname();
            std::cout << "students sorted by surnames" << std::endl;
            std::cout << std::endl;
            break;
        }
        //save to file
        case 13: {
            db.saveToFile("university_DataBase.txt");
            break;
        }
        //load from file
        case 14: {
            std::cout << "Loading latest saved database" << std::endl;
            db.loadFromFile("university_DataBase.txt");
            break;
        }
        default: {
            std::cout << "invalid option. Type again." << std::endl;
            std::cout << std::endl;
        }
        }
    } while (choice != 0);

    return 0;
}