#include "StudentList.h"
#include <fstream>
#include <cstring>
#include "Functions.h"
void StudentList::expand()
{
    this->cap += 5;
    auto newList = new Student[this->cap];
    for(int i = 0 ; i < this->curr; i++)
        newList[i] = this->listOfStudents[i];
    delete[] listOfStudents;
    this->listOfStudents = new Student[cap + 5];
    for(int i = 0 ; i < curr ; i++)
        this->listOfStudents[i] = newList[i];
    delete[] newList;
}
StudentList::StudentList(int cap):
cap(cap), curr(cap)
{
    this->listOfStudents = new Student[cap];
}
StudentList:: StudentList(std::ifstream& dbFile)
: cap(5), curr(0)
{
    this->listOfStudents = new Student[cap];
    if (dbFile.is_open())
    {
        if (!isEmpty(dbFile))
        {
            while(true)
            {
                if(this->curr == this->cap)
                    this->expand();
                int fn, grade;
                char firstName[128];
                char lastName[128];
                dbFile>>fn>>firstName>>lastName>>grade;
                if(dbFile.eof())
                    break;
                char* fName = new char[strlen(firstName) + 1];
                char* lName = new char[strlen(lastName)+1];
                strcpy(fName, firstName);
                strcpy(lName, lastName);
                Student curStudent(fn, fName, lName, grade);
                this->listOfStudents[this->curr]  = curStudent;
                this->curr++;
            }
        }
        else
            std::cout << "DataBase is empty" << std::endl;
    }
    else
        std::cout<<"DataBase could not be opened!"<<std::endl;
}
StudentList::StudentList(const StudentList & other):
cap(other.cap), curr(0)
{
    this->listOfStudents = new Student[other.cap];
    for(int i = 0 ; i < cap; i++, this->curr ++)
    {
        this->listOfStudents[i] = other.listOfStudents[i];
    }
}
StudentList& StudentList::operator=(const StudentList &other)
{
    if(this != &other)
    {
        delete [] this->listOfStudents;
        this->listOfStudents = new Student[other.cap];
        this->cap = other.cap;
        this->curr = 0;
        for(int i = 0 ; i < other.curr ; i++, this->curr ++)
        {
            this->listOfStudents[i] = other.listOfStudents[i];
        }
    }
    return *this;
}
StudentList::~StudentList()
{
    delete[] this->listOfStudents;
}
void StudentList::printDataBase()
{
    for(int i = 0 ; i < this->curr; i++)
    {
        this->listOfStudents[i].printStudent();
    }
}
void StudentList::addStudent(int fn, char* fName, char* lName, int grade)
{
    if(this->curr == this->cap)
        this->expand();
    Student newStudent(fn, fName, lName , grade);
    this->listOfStudents[this->curr] = newStudent;
    this->curr++;
}
bool StudentList::isPresent(int stFn)
{
    for(int i = 0 ; i <this->curr; i++ )
    {
        if (this->listOfStudents[i].getFn() == stFn)
            return true;
    }
    return false;

}
int StudentList::returnStudentIfPresent(int fn)
{
    for(int i = 0 ; i < this->curr; i++)
    {
        if(this->listOfStudents[i]. getFn() == fn)
            return i;
    }
    std::cout<<"Record not found"<<std::endl;
    return -1;

}
void StudentList::printStudent(int index)
{
    this->listOfStudents[index].printStudent();
}
void StudentList::editStudent(int index,  int newGrade)
{
   this->listOfStudents[index].setGrade(newGrade);
}
void StudentList::deleteStudent(int index)
{
    for(int i = 0 ; i < this->curr; i++)
    {
        if(i > index)
        {
            this->listOfStudents[i - 1] = this->listOfStudents[i];
        }
    }
    Student* newList = new Student[this->cap];
    for(int i = 0 ; i < this->curr -1; i++)
    {
        newList[i] = this->listOfStudents[i];
    }
    delete[] this->listOfStudents;
    this->listOfStudents = new Student[this->cap];
    for(int i = 0 ; i < this->curr - 1; i++)
        this->listOfStudents[i] = newList[i];
    this->curr --;
    delete[] newList;
}
void StudentList::writeToDataBase(std::ofstream & dbFile)
{
    for(int i = 0; i < this->curr; i++)
    {
        dbFile<<this->listOfStudents[i];
    }
}
