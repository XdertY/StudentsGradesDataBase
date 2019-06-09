
#ifndef DATA_BASE_STUDENTS_GRADES_FUNCTIONS_H
#define DATA_BASE_STUDENTS_GRADES_FUNCTIONS_H
#include <fstream>
#include<iostream>
#include "StudentList.h"
bool isEmpty(std::ifstream&);
void printMenu();
void create(StudentList&);
void sequentialSearch(StudentList&);
void update(StudentList&);
void deleteStudent(StudentList&);
#endif //DATA_BASE_STUDENTS_GRADES_FUNCTIONS_H
