#include "Student.h"

Student::Student(int facultyNumber, int academicYear, string firstName, string lastName)
        : facultyNumber(facultyNumber), academicYear(academicYear), firstName(std::move(firstName)), lastName(std::move(lastName)) {}

int Student::getFacultyNumber() const {
    return facultyNumber;
}

int Student::getAcademicYear() const {
    return academicYear;
}
