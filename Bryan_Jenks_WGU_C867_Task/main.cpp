#include <iostream>
#include <iomanip>
#include "roster.h"
using std::cout;
using std::endl;
using std::left;
using std::setw;

int main() {

    const int studentCount = 5; // For iterative loops with the student data records
    
    const string studentData[] = { // Our Raw data to be parsed
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Bryan,Jenks,bjenks4@wgu.edu,28,1,1,1,SOFTWARE"
    };

    // Demonstrating required functionality and printing out course information
    cout << left << setw(55)  << "Scripting and Programming - Applications – C867";
    cout << left << setw(8) << "C++";
    cout << left << setw(12) << "001354834";
    cout << left << setw(15) << "Bryan Jenks";
    cout << endl << endl;
    cout << "Parsing data and adding students to the roster..." << endl << endl;
    
    Roster* classRoster = new Roster(studentCount); // Create a new Roster pointer to our newly instantiated classRoster set to a default size of headCount
    
    for (int i = 0; i < studentCount; i++)
    { // Iteratively add new students to the roster by parsing their data and calling Roster::add()
        classRoster->parseDataAndAdd( studentData[i] );

    }
    
    cout << "All Sutdents added!" << endl << endl;

    // Provided pseudo code:
    classRoster->printAll();
    classRoster->printInvalidEmails();
    //loop through classRosterArray and for each element:
    for ( int i = 0; i < classRoster->headCount; i++ )
    {
        classRoster->printAverageDaysInCourse(classRoster->students[i]->getStudentID());
    }
    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    
    return 0;
}
