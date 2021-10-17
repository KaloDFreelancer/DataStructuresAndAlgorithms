#include "ElectiveDiscipline.h"
#include <iostream>

ElectiveDiscipline::ElectiveDiscipline(string name, unsigned int number, int minAcademicYear,
                                       int maxNumberOfStudents) : name(std::move(name)), number(number),
                                                                  minAcademicYear(minAcademicYear),
                                                                  maxNumberOfStudents(maxNumberOfStudents) {}

void ElectiveDiscipline::enrollStudent(Student *student) {
    //check if student isn't already enrolled
    for (auto &enrolledStudent: enrolledStudents) {
        if (enrolledStudent->getFacultyNumber() == student->getFacultyNumber()) {
            throw logic_error("Student is already enrolled!");
        }
    }
    //check for academic year
    if (student->getAcademicYear() < minAcademicYear) {
        throw logic_error("Student can't be enrolled in discipline based on his academic year!");
    } else {
        //check for empty spots
        if (enrolledStudents.size() < maxNumberOfStudents) {
            enrolledStudents.push_back(student);
        } else if (reserveStudents.size() < maxNumberOfStudents) {
            reserveStudents.push_back(student);
        } else {
            throw logic_error("There aren't any spots left even in the reserve.");
        }
    }
}

void ElectiveDiscipline::delistStudent(int facultyNumber) {
    //check if student is enrolled
    int index = -1;
    for (int i = 0; i < enrolledStudents.size(); ++i) {
        if (enrolledStudents[i]->getFacultyNumber() == facultyNumber) {
            index = i;
            break;
        }
    }
//    if student is enrolled
    if (index != -1) {
        enrolledStudents.erase(enrolledStudents.begin() + index);
        if (!reserveStudents.empty()) {
            enrolledStudents.push_back(reserveStudents.front());
            reserveStudents.erase(reserveStudents.begin());
        }
    } else {
        throw logic_error("Student isn't enrolled. You must have made a mistake.");
    }
}

bool ElectiveDiscipline::hasEnrolledStudent(int facultyNumber) const {
    for (auto &enrolledStudent: enrolledStudents) {
        if (enrolledStudent->getFacultyNumber() == facultyNumber) {
           return true;
        }
    }
    return false;
}
