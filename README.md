- STUDENT DATABASE MANAGEMENT SYSTEM -

OVERVIEW
This project is a simple Student Database Management System implemented in C++. The application allows users to manage a database of students, including adding new students, editing their information, displaying student details, searching by surname or PESEL(personal ID number in Polish system), sorting the database, and removing students. The data can also be saved to a text file and later loaded to the application for further manipulation. 

FEATURES
- add Student: Add new students to the database by providing details such as name, surname, date of birth, address, PESEL number, and gender.
- edit Student: Edit student information by searching with their index number.
- display Student: Display a student's details by searching with their index number.
- search by Surname: Search for students by their surname.
- search by PESEL: Search for students by their PESEL number.
- sort Students: Sort the database by PESEL number or surname.
- remove Student: Remove a student from the database using their index number.
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
   g++ -o student_database main.cpp dataBase.cpp student.cpp peselValidator.cpp
   
   This will compile the source files into an executable named student_database.
   ----------------------------------------------------------------------
   for CMake use commands:
   cd ..
   mkdir build
   cmake ..
   make

   This will compile the source files into an executable named student_database.

4. Run the Program:
   after compiling, you can run the program using the following command:
   ./student_database

USAGE
Once the program is running, you can interact with the application using the displayed menu. The options allow you to add, edit, display, search, sort, and remove students from the database. Additionally, you can save the database to a file or load it from a file to resume your work later.

SAVING AND LOADING DATA  
- save the database: To save the current database state to a file, choose the appropriate menu option. The file will be saved automatically with the name student_DataBase.txt.
- load the database: To load a previously saved database, select the load option from menu. The file will be saved automatically load from the previous session. 


   
   
   
   
   
   
