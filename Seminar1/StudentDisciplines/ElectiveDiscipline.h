#ifndef STUDENTDISCIPLINES_ELECTIVEDISCIPLINE_H
#define STUDENTDISCIPLINES_ELECTIVEDISCIPLINE_H

#include <string>
#include <vector>
#include "Student.h"

using namespace std;
class ElectiveDiscipline {
private:
    string name;
    unsigned int number;
    int minAcademicYear;
    int maxNumberOfStudents;
protected:
    vector<Student*> enrolledStudents;
    vector<Student*> reserveStudents;
public:
    ElectiveDiscipline(string name, unsigned int number, int minAcademicYear, int maxNumberOfStudents);
    void enrollStudent(Student* student);
    void delistStudent(int facultyNumber);
};


#endif //STUDENTDISCIPLINES_ELECTIVEDISCIPLINE_H
