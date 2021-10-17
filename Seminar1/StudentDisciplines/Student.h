#ifndef STUDENTDISCIPLINES_STUDENT_H
#define STUDENTDISCIPLINES_STUDENT_H
#include <string>
using namespace std;
class Student {
private:
    int facultyNumber;
    int academicYear;
    string firstName;
    string lastName;
public:
    Student(int facultyNumber, int academicYear, string firstName, string lastName);

    int getFacultyNumber() const;

    int getAcademicYear() const;
};


#endif //STUDENTDISCIPLINES_STUDENT_H
