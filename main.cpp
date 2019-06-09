#include <iostream>
#include <fstream>
#include <limits>
#include "Student.h"
#include "StudentList.h"
#include "Functions.h"


int main()
{
    std::ifstream dBase("StudentGrades.db");
    StudentList listOfStudents(dBase);
    dBase.close();
    int choice;
    while(true) {
        printMenu();
        while(!(std::cin>>choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Wrong input, please enter a number: ";
        }
        switch (choice) {
            case 1:
            {
                system("clear");
                create(listOfStudents);
                break;
            }
            case 2:
            {
                system("clear");
                listOfStudents.printDataBase();
                break;
            }
            case 3:
            {
                system("clear");
                sequentialSearch(listOfStudents);
                break;
            }
            case 4:
            {
                system("clear");
                update(listOfStudents);
                break;
            }
            case 5:
            {
                system("clear");
                deleteStudent(listOfStudents);
                break;
            }
            case 6:
            {
                std::ofstream odBase("StudentGrades.db", std::ios::out);
                listOfStudents.writeToDataBase(odBase);
                odBase.close();
                return 0;
            }
            default:
            {
                std::cerr<< "Invalid Index"<<std::endl;
            }
       }
    }

}