#ifndef STUDENTDISCIPLINES_ELECTIVEDISCIPLINESEXTENDED_H
#define STUDENTDISCIPLINES_ELECTIVEDISCIPLINESEXTENDED_H


#include "../ElectiveDiscipline.h"

class ElectiveDisciplinesExtended : public ElectiveDiscipline{
public:
    using ElectiveDiscipline::ElectiveDiscipline;
    unsigned int numberOfEnrolledStudents() const;
    unsigned int numberOfReserveStudents() const;
};


#endif //STUDENTDISCIPLINES_ELECTIVEDISCIPLINESEXTENDED_H
