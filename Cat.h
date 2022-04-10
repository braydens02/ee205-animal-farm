///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   08_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
#include "catDatabase.h"
#include "config.h"

class Cat {
public:
    Cat() ;
    Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight);
    Cat* next{} ;
    bool print() ;
    bool validate() ;
    static bool validateName( const char* newName ) ;
    static bool validateGender( Gender newGender ) ;
    static bool validateBreed( Breed newBreed ) ;
    static bool validateWeight( Weight newWeight ) ;
    void setName( const char *newName ) ;
    void setGender( Gender newGender ) ;
    void setBreed( Breed newBreed ) ;
    void setWeight( Weight newWeight ) ;

protected:
    char        name[MAX_CATS] ;
    enum Gender gender ;
    enum Breed  breed ;
    bool        isFixed{} ;
    Weight      weight{} ;
private:
    void        setMemberData() ;
};

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
