#include <algorithm>
#include <iostream>
#include <limits>
#include <regex>
#include "dataBase.hpp"

void displayMenu() {
    std::cout << "============== Menu ==============" << std::endl;
    std::cout << "1 - Add a student" << std::endl;
    std::cout << "2 - Edit a student" << std::endl;
    std::cout << "3 - Display a student by index number" << std::endl;
    std::cout << "4 - Display database" << std::endl;
    std::cout << "5 - Search a student by surname" << std::endl;
    std::cout << "6 - Search a student by PESEL" << std::endl;
    std::cout << "7 - Remove by index number" << std::endl;
    std::cout << "8 - Sort by PESEL" << std::endl;
    std::cout << "9 - Sort by surname" << std::endl;
    std::cout << "10 - Save to file" << std::endl;
    std::cout << "11 - Load from file" << std::endl;
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
    StudentDataBase db;
    int choice;
    std::string students_DataBase;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
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
            std::cout << "enter a name: ";
            std::getline(std::cin, name);

            std::cout << "enter a surname: ";
            std::getline(std::cin, surname);

            std::cout << "date of birth: " << std::endl;
            // day of birth
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

            std::cout << "enter an address: ";
            std::getline(std::cin, address);

            std::cout << "enter a zipcode: ";
            std::getline(std::cin, zipcode);

            std::cout << "enter a city: ";
            std::getline(std::cin, city);

            std::cout << "enter a nationality: ";
            std::getline(std::cin, nationality);

            std::cout << "REQUIRED - ";
            std::cout << "enter index number(e.g.111111Fg): ";
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

            db.addStudent(Student(name, surname, day, month, year, address, zipcode,
                                  city, nationality, indexNumber, pesel, gender));
            std::cout << std::endl;
            std::cout << "student added successfully to database!" << std::endl;
            std::cout << std::endl;
            break;
        }
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
            std::cout << "=========== STUDENT IN: " << indexNumber << " ===========" << std::endl;
            db.editStudentByIndexNumber(indexNumber);
            std::cout << std::endl;
            break;
        }
        case 3: {
            std::string indexNumber;
            std::cout << "enter student's index number: ";
            std::getline(std::cin, indexNumber);
            std::cout << std::endl;
            std::cout << "=========== STUDENT IN: " << indexNumber << " ===========" << std::endl;
            db.displayStudentByIndex(indexNumber);
            std::cout << std::endl;
            break;
        }
        case 4: {
            std::cout << std::endl;
            std::cout << "=========== STUDENT DATABASE ===========" << std::endl;
            db.displayAllStudents();
            std::cout << std::endl;
            break;
        }
        case 5: {
            std::string surname;
            std::vector<Student> results;
            bool found = false;

            do {
                std::cout << "enter student's surname: ";
                std::getline(std::cin, surname);

                std::string lowerSurname = surname;
                std::transform(lowerSurname.begin(), lowerSurname.end(), lowerSurname.begin(), ::tolower);

                results = db.findStudentBySurname(lowerSurname);
                std::cout << std::endl;

                if (results.empty()) {
                    std::cout << "Student with surname " << surname << " not found. Try again? (Y/N): ";
                    char tryAgain;
                    std::cin >> tryAgain;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (tryAgain != 'Y' && tryAgain != 'y') {
                        std::cout << "Exit searching " << std::endl;
                        break;
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "=========== STUDENT " << surname << " ===========" << std::endl;
                    for (const auto& student : results) {
                        db.displayStudentByIndex(student.getIndexNumber());
                        std::cout << std::endl;
                    }
                    found = true;
                }
            } while (!found);
            break;
        }
        case 6: {
            std::string pesel;
            std::cout << "enter a PESEL: ";
            std::getline(std::cin, pesel);
            Student foundStudent = db.findStudentByPesel(pesel);

            if (foundStudent.getPesel().empty()) {
                std::cout << "student with PESEL: " << pesel << " not found" << std::endl;
                std::cout << std::endl;
            } else {
                std::string indexNumber = foundStudent.getIndexNumber();
                std::cout << std::endl;

                // display student's data using displayStudentByIndex
                std::cout << "=========== STUDENT PESEL:" << pesel << " ===========" << std::endl;
                db.displayStudentByIndex(indexNumber);
                std::cout << std::endl;
            }
            break;
        }
        case 7: {
            std::string indexNumber;
            std::cout << "enter student's index number: ";
            std::getline(std::cin, indexNumber);
            db.removeStudentByIndexNumber(indexNumber);
            std::cout << std::endl;
            break;
        }
        case 8: {
            db.sortAndDisplayByPesel();
            std::cout << "students sorted by pesel's number" << std::endl;
            std::cout << std::endl;
            break;
        }
        case 9: {
            db.sortAndDisplayBySurname();
            std::cout << "students sorted by surnames" << std::endl;
            std::cout << std::endl;
            break;
        }
        case 10: {
            db.saveToFile(students_DataBase);
            break;
        }
        case 11: {
            std::cout << "Loading latest saved database" << std::endl;
            db.loadFromFile(students_DataBase);
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