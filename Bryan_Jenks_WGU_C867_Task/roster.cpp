#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

/*===============================
          CLASS CONSTRUCTOR
===============================*/
Roster::Roster() // Blank roster with no determined headcount of students
{
    this->headCount = 0; // No students to add
    this->lastStudent = -1; // we cant use 0 as thats a valid array index so -1
    this->students = nullptr; // No students exist so we dont want anything yet
}
Roster::Roster( int headCount ) // Full constructor setting the maximum size of the class Roster
{
    this->headCount = headCount;
    this->lastStudent = -1; // we cant use 0 as thats a valid array index so -1
    this->students = new Student * [headCount]; // New student pointer to an array of student instances
}
Roster::~Roster()
{ // For each student in the roster up to the number of headcount, delete the students then the roster
    for ( int i = 0; i < headCount; i++ )
    {
        delete this->students[i]; // Remove each student from memory itteratively
    }
    delete this; // Remove empty roster from memory
}
/*====================================
                METHODS
======================================*/
void Roster::parseDataAndAdd( string rawData )
{ // Returns a vector of strings (parsed data)
    std::vector<string> dataPoints; // Our data holding container
    std::stringstream inputSStream(rawData); // Function input string to be parsed

    while( inputSStream.good() )
    { // Parse the string on the commas then add each data point to result vector
        string data;
        getline( inputSStream, data, ',');
        dataPoints.push_back(data);
    }
    add( dataPoints.at(0), // ID
         dataPoints.at(1), // First Name
         dataPoints.at(2), // Last Name
         dataPoints.at(3), // Email Address
         stoi( dataPoints.at(4) ), // Age
         stoi( dataPoints.at(5) ), // Days in course 1
         stoi( dataPoints.at(6) ), // Days in course 2
         stoi( dataPoints.at(7) ), // Days in course 3
         convert( dataPoints.at(8) ) // Degree Program
       );
}
DegreeProgram Roster::convert( string str)
{ // Convert the string passed from the add function into an enum
    if(str == "SECURITY") return SECURITY;
    else if(str == "NETWORK") return NETWORK;
    else if(str == "SOFTWARE") return SOFTWARE;
    else return NONE;
}
void Roster::add( string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram )
{ // Add a new student to the roster
    if ( lastStudent < headCount )
    { // Making sure we do not add more students than we have counted already
        lastStudent++; // Increment so we dont overflow our head count
        this->students[lastStudent] = new Student();
        this->students[lastStudent]->setStudentID(studentID);
        this->students[lastStudent]->setFirstName(firstName);
        this->students[lastStudent]->setLastName(lastName);
        this->students[lastStudent]->setEmailAddress(emailAddress);
        this->students[lastStudent]->setAge(age);
        int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
        this->students[lastStudent]->setCourseCompletionDays(days);
        this->students[lastStudent]->setDegreeProgram(degreeProgram);
    }
    else // If you attempt to add a 6th student while head count is 5 then you exceed head count, error thrown
    {
        std::cerr << std::endl << "ERROR! YOUR ROSTER HAS EXCEEDED YOUR HEAD COUNT OF STUDENTS!" << std::endl << std::endl;
    }
}
void Roster::printAll() // Print a list of all students and all their data from the roster
{
    std::cout << "Displaying all students:" << std::endl << std::endl;
    for (int i = 0; i <= this->lastStudent; i++ )
    {
        
        (this->students)[i]->print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Roster::remove( string studentID )
{ // Removes students from the roster by student ID.
    
    bool found = false; // Is the student ID in the roster?
    
    for ( int i = 0; i <= lastStudent; i++ )
    {
        if ( this->students[i]->getStudentID() == studentID ) // Student found
        {
            found = true; // Dont trigger the error message
            delete this->students[i];
            this->students[i] = this->students[lastStudent]; // Removed student is replaced by the last student in the roster to fill the "hole" in the array
            lastStudent--; // Reduce Class Roster Size
            std::cout << "Successfully Removed student: " << studentID << std::endl << std::endl;
        }
    }
    if (!found)
    { // If the student ID does not exist, the function prints an error message indicating that the student was not found.
        std::cerr << "ERROR! Student: " << studentID << " NOT FOUND!" << std::endl << std::endl;
    }
    
}
void Roster::printAverageDaysInCourse(string studentID)
{
    bool found = false; // Is the student ID in the roster?
    
    for ( int i = 0; i <= lastStudent; i++ )
    {
        if ( this->students[i]->getStudentID() == studentID ) // Student found
        {
            found = true;
            int* days = this->students[i]->getCourseCompletionDays(); // Make a holding array
            double averageDays = static_cast<double>(days[0] + days[1] + days[2]) / 3.0; // averages of intergers can still be floating point
            std::cout << "Average course completion days for student " << studentID << " is: "
            << averageDays << std::endl << std::endl;
        }
    }
    if (!found)
    {
        std::cerr << "ERROR! Student: " << studentID << " NOT FOUND!" << std::endl << std::endl;
    }
    
}
void Roster::printInvalidEmails()
{
    std::cout << "Displaying Students With Invalid Email Addresses:" << std::endl << std::endl;
    bool found = false; // Any invalid emails found?
    
    for ( int i = 0; i <= lastStudent; i++ )
    { // Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
        string email = this->students[i]->getEmailAddress();
        if (
            (email.find('.') == string::npos) || // It does not find a '.' anywhere
            (email.find('@') == string::npos) || // It does not find a '@' anywhere
            !(email.find(' ') == string::npos)   // it DOES find a ' '
            )
        { // Email contains necessary characters and they are placed in the email
          // Edge case is if a '.' is found in the name like 'bryan.jenks' and not in
          // the '.com' then the email could be invalid but for this application this suffices
            found = true;
            this->students[i]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    if (!found)
    {
        std::cout << "No Invalid emails found!" << std::endl << std::endl;
    }
}
void Roster::printByDegreeProgram( DegreeProgram degreeProgram )
{
    std::cout << "Displaying Students in the " << degreeProgramStrings[degreeProgram] << " degree program" << std::endl << std::endl;
    for ( int i = 0; i <= lastStudent; i++ )
    {
        if (this->students[i]->getDegreeProgram() == degreeProgram)
        {
            this->students[i]->print();
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
