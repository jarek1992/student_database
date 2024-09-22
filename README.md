 -- STUDENT DATABASE MANAGEMENT SYSTEM --

OVERVIEW
This project is a simple University Database Management System implemented in C++. The application allows users to manage a database of students and employees, including adding new students or employees, editing their information, displaying details, searching by surname or PESEL(personal ID number in Polish system), sorting the database, and removing. The data can also be saved to a text file and later loaded to the application for further manipulation. 

FEATURES
- add Student: Add new students to the database by providing details such as name, surname, date of birth, address, PESEL number, and gender.
- edit Student: Edit student information by searching with their index number.
- display Student: Display a student's details by searching with their index number.
- add Employee: Add new employees to the database by providing details such as employeeJob, name, surname, address, PESEL number, salary , and gender.
- edit Employee: Edit employee information by searching with their surname.
- display Database.
- search by Surname: Search for students and employees by their surname.
- search by PESEL: Search for students and employees by their PESEL number.
- remove Student: Remove a student from the database using their index number.
- remove Employee: Remove an employee from the database using their PESEL.
- sort Students: Sort the database by PESEL number or surname.
- save/Load Database: Save the current state of the database to a text file and load it back into the application.

Installation
To run this project, you need to have a C++ compiler installed on your system. 

Steps to Clone and Run
1. Clone the repository using the following command:
   git clone https://github.com/jarek1992/student_database.git
   or use SSH:
   git clone git@github.com:jarek1992/student_database.git
2. Navigate to the Project Directory:
   cd student_database/source
3. Compile the Program
   you can build the project using tools like CMake or 'g++'.

   for 'g++' use command:
   g++ -o university_database main.cpp dataBase.cpp student.cpp peselValidator.cpp person.cpp employee.cpp

   This will compile the source files into an executable named university_database.

   -----------------------------------------------------------------------------

   for CMake use commands:
   cd ..
   mkdir build
   cmake ..
   make

   This will compile the source files into an executable named university_database.

5. Run the Program:
   after compiling, you can run the program using the following command:
   ./university_database

USAGE
Once the program is running, you can interact with the application using the displayed menu. The options allow you to add, edit, display, search, sort, and remove from the database. Additionally, you can save the database to a file or load it from a file to resume your work later.

SAVING AND LOADING DATA  
- save the database: To save the current database state to a file, choose the appropriate menu option. The file will be saved automatically with the name university_DataBase.txt.
- load the database: To load a previously saved database, select the load option from menu. The file will be saved automatically load from the previous session. 


   
   
   
   
   
   
