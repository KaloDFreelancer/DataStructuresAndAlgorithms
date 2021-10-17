#include "gtest/gtest.h"
#include "../Student.h"
#include "ElectiveDisciplinesExtended.h"

TEST(StudentTest, testStudentPublicMethods) {
    Student student(10001, 1, "Kaloyan", "Mitev");
    ASSERT_EQ(10001, student.getFacultyNumber());
    ASSERT_EQ(1, student.getAcademicYear());
}

TEST(ElectiveDiscipline, testSuccessfulEnrollStudent) {
    ElectiveDisciplinesExtended discipline("Introduction to Programming", 111110, 1, 2);
    auto *student = new Student(10001, 1, "Kaloyan", "Mitev");

    discipline.enrollStudent(student);
    ASSERT_EQ(1, discipline.numberOfEnrolledStudents());

    delete student;
}

TEST(ElectiveDiscipline, testSuccessfulEnrollToReserveStudent) {
    ElectiveDisciplinesExtended discipline("Introduction to Programming", 111110, 1, 1);
    auto *student1 = new Student(10001, 1, "Kaloyan", "Mitev");
    auto *student2 = new Student(10002, 1, "Kaloyan", "Mitev");

    discipline.enrollStudent(student1);
    discipline.enrollStudent(student2);
    ASSERT_EQ(1, discipline.numberOfReserveStudents());

    delete student1;
    delete student2;
}

TEST(ElectiveDiscipline, testUnsuccessfulEnrollStudentBecauseAcademicYear) {
    ElectiveDisciplinesExtended discipline("OOP", 111110, 2, 2);
    auto *student = new Student(10001, 1, "Kaloyan", "Mitev");

    try {
        discipline.enrollStudent(student);
        FAIL();
    }
    catch (const logic_error &err) {
        // check exception
        ASSERT_STREQ("Student can't be enrolled in discipline based on his academic year!", err.what());
    }

    delete student;
}

TEST(ElectiveDiscipline, testUnsuccessfulEnrollStudentBecauseAlreadyEnrolled) {
    ElectiveDisciplinesExtended discipline("OOP", 111110, 1, 2);
    auto *student = new Student(10001, 1, "Kaloyan", "Mitev");

    discipline.enrollStudent(student);
    try {
        discipline.enrollStudent(student);
        FAIL();
    }
    catch (const logic_error &err) {
        // check exception
        ASSERT_STREQ("Student is already enrolled!", err.what());
    }
    delete student;
}

TEST(ElectiveDiscipline, testUnsuccessfulEnrollStudentBecauseNoSpotsLeft) {
    ElectiveDisciplinesExtended discipline("OOP", 111110, 1, 2);
    auto *student1 = new Student(10001, 1, "Kaloyan", "Mitev");
    auto *student2 = new Student(10002, 1, "Kaloyan", "Mitev");
    auto *student3 = new Student(10003, 1, "Kaloyan", "Mitev");
    auto *student4 = new Student(10004, 1, "Kaloyan", "Mitev");
    auto *student5 = new Student(10005, 1, "Kaloyan", "Mitev");

    discipline.enrollStudent(student1);
    discipline.enrollStudent(student2);
    discipline.enrollStudent(student3);
    discipline.enrollStudent(student4);

    try {
        discipline.enrollStudent(student5);
        FAIL();
    }
    catch (const logic_error &err) {
        // check exception
        ASSERT_STREQ("There aren't any spots left even in the reserve.", err.what());
    }

    delete student1;
    delete student2;
    delete student3;
    delete student4;
    delete student5;
}


TEST(ElectiveDiscipline, testDelistStudentWrongFacultyNumber) {
    ElectiveDisciplinesExtended discipline("OOP", 111110, 1, 2);
    try {
        discipline.delistStudent(40000);
        FAIL();
    }
    catch (const logic_error &err) {
        // check exception
        ASSERT_STREQ("Student isn't enrolled. You must have made a mistake.", err.what());
    }
}

TEST(ElectiveDiscipline, testSuccessfulDelistStudentRemoval) {
    int studentFacultyNumber = 10001;
    ElectiveDisciplinesExtended discipline("OOP", 111110, 1, 2);
    auto *student = new Student(studentFacultyNumber, 1, "Kaloyan", "Mitev");

    discipline.enrollStudent(student);
    discipline.delistStudent(studentFacultyNumber);

    ASSERT_EQ(discipline.numberOfEnrolledStudents(), 0);

    delete student;
}

TEST(ElectiveDiscipline, testSuccessfulDelistStudentReservePushToEnrollment) {
    int studentFacultyNumber1 = 10001;
    int studentFacultyNumber2 = 10002;
    ElectiveDisciplinesExtended discipline("OOP", 111110, 1, 1);
    auto *student1 = new Student(studentFacultyNumber1, 1, "Kaloyan", "Mitev");
    auto *student2 = new Student(studentFacultyNumber2, 1, "Kaloyan", "Mitev");

    discipline.enrollStudent(student1);
    discipline.enrollStudent(student2);
    discipline.delistStudent(studentFacultyNumber1);

    ASSERT_EQ(discipline.numberOfEnrolledStudents(), 1);
    ASSERT_EQ(discipline.numberOfReserveStudents(), 0);
    delete student1;
    delete student2;
}
