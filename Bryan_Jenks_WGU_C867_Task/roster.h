#pragma once
#include "student.h"


class Roster
{
public: // Roster Data Members
    int lastStudent; // The index of the last student in the student object array
    int headCount; // Size of the Roster
    Student** students; // An array of pointers to the student objects
/*===============================
         DE/CONSTRUCTORS
===============================*/
    Roster(); // Default Constructor
    Roster( int headCount ); // Full constructor setting the maximum size of the class Roster
    ~Roster(); // Destructor
/*===============================
            METHODS
===============================*/
    void parseDataAndAdd( string rawData ); // To pass a whole raw data record to one function and keep all the processing in the background
    DegreeProgram convert( string str); // To convert the string value of the program to an enum for the add function to use
    void add( string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram );
    void printAll(); // Print a list of all students and all their data from the roster
    void remove( string studentID ); // Remove a student from the roster and shift students so there's no holes in the array
    void printAverageDaysInCourse( string studentID ); // Prints a student’s average number of days in the three courses.
    void printInvalidEmails(); // Verifies student email addresses and displays all invalid email addresses to the user.
    void printByDegreeProgram( DegreeProgram degreeProgram ); //that prints out student information for a degree program specified by an enumerated type.

};




