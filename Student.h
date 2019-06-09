#ifndef DATA_BASE_STUDENTS_GRADES_STUDENT_H
#define DATA_BASE_STUDENTS_GRADES_STUDENT_H

#include <fstream>

class Student
{
    int fn;
    char* firstName;
    char* lastName;
    int grade;
public:
    explicit Student(int = 0 , char* = "", char* = "", int = 0);
    Student(const Student&);
    Student& operator=(const Student&);
   ~Student();
    void setGrade(int);
    void printStudent() const;
    int getFn() const   ;
    friend std::ostream& operator<<(std::ostream&, const Student&);
};



#endif
