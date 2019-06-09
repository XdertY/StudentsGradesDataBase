#include <fstream>
#include "Functions.h"
#include <cstring>
#include<iostream>
#include <limits>

bool isEmpty(std::ifstream& dbFile)
{
    dbFile.seekg(0 ,std::ios::end);
    int length = dbFile.tellg();
    if(length == 0)
        return true;
    else
    {
        dbFile.seekg(0, std::ios::beg);
        return false;
    }
}
void printMenu() {
    std::cout << "1. Create a new student" << std::endl;
    std::cout <<"2. Print Database"<<std::endl;
    std::cout << "3. Search for a student" << std::endl;
    std::cout << "4. Update a student" << std::endl;
    std::cout << "5. Delete a student" << std::endl;
    std::cout << "6. Save and exit" << std::endl;
    std::cout << "Enter the index of your choice: ";
}
void create( StudentList& listOfStudents)
{

    int fn;

    std::cout<<"Enter student's FN: ";
    std::cin>>fn;
    while(std::cin.fail() || listOfStudents.isPresent(fn) || fn/100000 != 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input, please enter a valid FN: ";
        std::cin>>fn;
    }
    char* firstName = new char[20];
    char* lastName = new char[20];
    int grade;
    std::cout<<"Enter the student's first Name: ";
    std::cin>>firstName;
    std::cout<<"Enter the student's last Name: ";
    std::cin>>lastName;
    do
    {
        std::cout<<"Enter student's grade: ";
        std::cin>>grade;
    }
    while(grade < 2 || grade > 6);
    char* stFirstName = new char[strlen(firstName) + 1];
    strcpy(stFirstName, firstName);
    char* stLastName = new char[strlen(lastName) + 1];
    strcpy(stLastName, lastName);
    delete[] firstName;
    delete[] lastName;
    listOfStudents.addStudent(fn, stFirstName, stLastName, grade);
    delete[] stFirstName;
    delete[] stLastName;
}
void sequentialSearch(StudentList& studentList)
{
    int fn;
    std::cout<<"Enter the student's fn: ";
    std::cin>>fn;
    int index = studentList.returnStudentIfPresent(fn);
    if(index >= 0)
    {
        studentList.printStudent(index);
    }
}
void update(StudentList& listOfStudents)
{
    int fn, newGrade;
    do {
        std::cout << "Enter the FN of the student , whose grade you want to change, followed by the new grade: ";
        std::cin >> fn >> newGrade;
    } while(newGrade < 2 || newGrade > 6);
    if(listOfStudents.returnStudentIfPresent(fn) >= 0)
    {
        std::cout<<"Student updated!"<<std::endl;
        listOfStudents.editStudent(listOfStudents.returnStudentIfPresent(fn), newGrade);
    }
    else return;

}
void deleteStudent(StudentList& list)
{
    int fn;
    std::cout<<"Enter the FN of the student , you want to delete: ";
    std::cin>>fn;
    if(list.returnStudentIfPresent(fn) >= 0)
    {
        list.deleteStudent(list.returnStudentIfPresent(fn));
    }
}
