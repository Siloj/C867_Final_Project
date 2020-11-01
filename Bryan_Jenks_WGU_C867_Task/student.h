#pragma once
#include "degree.h"

class Student
{
public: // Declare size of the arrays holding numbers for course completion days (its always 3)
    const static int courseCompletionArraySize = 3;
    
private: // Set up the student data that only the setters modify and getters access
/*===============================
    PRIVATE DATA MEMEBERS
===============================*/
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int courseCompletionDays[courseCompletionArraySize]; // Static allocation because for this project it is always 3 values
    DegreeProgram degreeProgram;
    
public: // Define getters, setters, methods, and De/Constructors
/*===============================
          DE/CONSTRUCTORS
===============================*/
    Student(); // Default Constructor
    Student( string studentID, string firstName, string lastName, string emailAddress, int age, int courseCompletionDays[], DegreeProgram degreeProgram ); // Full constructor
    ~Student();
/*===============================
            GETTERS
===============================*/
    string getStudentID() const; // TODO will these const getters cause issues?
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    int* getCourseCompletionDays();
    DegreeProgram getDegreeProgram() const;
    
/*===============================
            SETTERS
===============================*/
    void setStudentID( string studentID );
    void setFirstName( string firstName );
    void setLastName( string lastName );
    void setEmailAddress( string emailAddress );
    void setAge( int age );
    void setCourseCompletionDays( int courseCompletionDays[] );
    void setDegreeProgram( DegreeProgram degreeProgram );

/*===============================
            METHODS
===============================*/
    void print();
};
