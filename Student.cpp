#include "Student.h"
#include <cstring>
#include <iostream>
Student ::Student(int fn, char * firstName, char *lastName, int grade) :
fn(fn), grade(grade)
{
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
}
Student::Student(const Student & other) :
fn(other.fn), grade(other.grade)
{
    this->firstName = new char[strlen(other.firstName) + 1];
    strcpy(this->firstName, other.firstName);
    this->lastName = new char[strlen(other.lastName) + 1];
    strcpy(this->lastName, other.lastName);
}
Student&  Student::operator=(const Student&other)
{
    if(this != &other)
    {
        delete[] this->firstName;
        delete[] this->lastName;
        this->firstName = new char[strlen(other.firstName) +1];
        this->lastName = new char[strlen(other.lastName) +1];
        strcpy(this->firstName, other.firstName);
        strcpy(this->lastName, other.lastName);
        this->fn = other.fn;
        this->grade = other.grade;
    }
    return *this;
}
Student::~Student()
{
    delete[] this->firstName;
    delete[] this->lastName;
}
void Student::setGrade(int grade)
{
    this->grade = grade;
}
void Student::printStudent() const
{
    std::cout<<this->fn<<" "<<this->firstName<<" "<<this->lastName<<" "
    <<this->grade<<std::endl;
}
int Student::getFn() const
{
    return this->fn;
}
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.fn<<" "<< student.firstName <<" "
    <<student.lastName<< " " <<student.grade<<std::endl;
    return os;
}