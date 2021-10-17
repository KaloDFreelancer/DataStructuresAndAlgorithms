#include "ElectiveDisciplinesExtended.h"

unsigned int ElectiveDisciplinesExtended::numberOfEnrolledStudents() const {
    return enrolledStudents.size();
}

unsigned int ElectiveDisciplinesExtended::numberOfReserveStudents() const {
    return reserveStudents.size();
}
