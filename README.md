Student Record Management System

Overview
This C++ program is a Student Record Management System designed to manage and track student grades efficiently. This was developed in an attempt to apply the different concepts data structures and algorithms to make a project that can be expanded on even further. The project provides functionality for recording, displaying, modifying, and deleting student records. It also calculates and displays student grades based on their marks.

Features

Add Student Records: Input student details including roll number, name, and marks in various subjects.
Display All Records: View all student records stored in the binary file.
Search Student Records: Retrieve and display records for a specific student based on roll number.
Modify Records: Update existing student records.
Delete Records: Remove student records from the system.
View Class Results: Display a tabular view of all student records with their grades.
Result Menu: Navigate between different result-related options.
Functionality
inforOfStudent Class: Manages individual student records, including calculating average marks and grades.
File Operations: Records are stored in a binary file named student.dat, with functionality for creating, reading, updating, and deleting records.
Exception Handling: Includes basic exception handling for user input validation.

Code Breakdown
Classes and Structs:

inforOfStudent: Manages student data and operations related to student records.
Calculate: Inherits from inforOfStudent for calculation-related operations.
variables: Inherits from inforOfStudent with additional functionalities.

Main Functions:

write_student(): Writes student data to the binary file.
display_all(): Displays all student records.
display_sp(int n): Displays the record of a student with a specific roll number.
modify_student(int n): Modifies a student record.
delete_student(int n): Deletes a student record.
class_result(): Displays results of all students in a tabular format.
result(): Provides a menu for viewing results.
intro(): Displays the introductory screen.
entry_menu(): Provides a menu for record entry and management.

Usage
Compile the Program: Use a C++ compiler to compile the source code.
Run the Program: Execute the compiled program to access the main menu.
Navigate Menus: Follow prompts to add, view, modify, or delete student records.

