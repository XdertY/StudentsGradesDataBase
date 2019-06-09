#ifndef DATA_BASE_STUDENTS_GRADES_STUDENTLIST_H
#define DATA_BASE_STUDENTS_GRADES_STUDENTLIST_H
#include <fstream>
#include "Student.h"
class StudentList
{
    Student* listOfStudents;
    int curr;
    int cap;
    void expand();
public:
    explicit StudentList(int = 0);
    explicit StudentList(std::ifstream&);
    StudentList(const StudentList&);
    StudentList&operator=(const StudentList&);
    ~StudentList();
    void printDataBase();
    void addStudent(int , char*, char* , int);
    bool isPresent(int);
    int returnStudentIfPresent(int);
    void printStudent(int);
    void editStudent(int, int);
    void deleteStudent(int);
    void writeToDataBase(std::ofstream&);

};


#endif //DATA_BASE_STUDENTS_GRADES_STUDENTLIST_H
