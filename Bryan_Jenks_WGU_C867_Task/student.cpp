#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "degree.h"
using std::cout;
using std::left;
using std::setw;

/*====================================
          CLASS CONSTRUCTORS
======================================*/
// ------ Default Constructor ------- //
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = -1;
    for ( int i = 0; i < courseCompletionArraySize; i++ )
    {
        this->courseCompletionDays[i] = 0;
    }
    this->degreeProgram = NONE;
} // ----- END Default Constructor

// ------ True Constructor ------- //
Student::Student( string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], DegreeProgram degreeProgram )
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i<courseCompletionArraySize; i++)
    {
        this->courseCompletionDays[i] = courseCompletionDays[i];
    }
    this->degreeProgram = degreeProgram;
} // ----- END True Constructor

Student::~Student() // ------ Destructor ------ //
{
}
/*====================================
                GETTERS
======================================*/
string Student::getStudentID() const
{
    return studentID;
}
string Student::getFirstName() const
{
    return firstName;
}
string Student::getLastName() const
{
    return lastName;
}
string Student::getEmailAddress() const
{
    return emailAddress;
}
int Student::getAge() const
{
    return age;
}
int * Student::getCourseCompletionDays()
{
    return courseCompletionDays;
}
DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

/*====================================
            CLASS SETTERS
======================================*/
void Student::setStudentID( string studentID )
{
    this->studentID = studentID;
}
void Student::setFirstName( string firstName )
{
    this->firstName = firstName;
}
void Student::setLastName( string lastName )
{
    this->lastName = lastName;
}
void Student::setEmailAddress( string emailAddress )
{
    this->emailAddress = emailAddress;
}
void Student::setAge( int age )
{
    this->age = age;
}
void Student::setCourseCompletionDays( int courseCompletionDays[] )
{
    for (int i = 0; i < courseCompletionArraySize; i++)
    {
        this->courseCompletionDays[i] = courseCompletionDays[i];
    }
}
void Student::setDegreeProgram( DegreeProgram program ) {
    this->degreeProgram = program;
}

/*====================================
               METHODS
======================================*/
void Student::print()
{   // This commented block is for nicer formatting of student records output
//    cout << left << setw(5)  << studentID;
//    cout << left << setw(10) << firstName;
//    cout << left << setw(10) << lastName;
//    cout << left << setw(30) << emailAddress;
//    cout << left << setw(10) << age;
//    cout << left << setw(10) << courseCompletionDays[0];
//    cout << left << setw(10) << courseCompletionDays[1];
//    cout << left << setw(10) << courseCompletionDays[2];
//    cout << left << setw(20) << degreeProgramStrings[getDegreeProgram()];

    // This is the requested format:
    cout << studentID << "\t"
         << "First Name: " << firstName << "\t"
         << "Last Name: " << lastName << "\t"
         << "Age: " << age << "\t"
         << "daysInCourse: {" << courseCompletionDays[0] << ", "
         << courseCompletionDays[1] << ", "
         << courseCompletionDays[2] << "} "
         << "Degree Program: " << degreeProgramStrings[getDegreeProgram()];
}
