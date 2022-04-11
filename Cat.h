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
#pragma once
#include "config.h"

#define MAX_CATS (1024)
#define MAX_CAT_NAMES (50)

enum Gender {UNKNOWN_GENDER, MALE, FEMALE} ;

enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX} ;

enum Color {UNKNOWN_COLOR, BLACK, WHITE, RED, YELLOW, ORANGE, GREEN, BLUE, PURPLE, PINK} ;

class Cat {
public:
    Cat() ;
    Cat(const char *newName, Gender newGender, Breed newBreed, Weight newWeight) ;
    Cat* next ;
    bool print() const noexcept ;
    bool validate() const noexcept ;
    static bool validateName( const char* newName ) ;
    static bool validateGender( Gender newGender ) ;
    static bool validateBreed( Breed newBreed ) ;
    static bool validateWeight( Weight newWeight ) ;
    void setName( const char *newName ) ;
    void setGender( Gender newGender ) ;
    void setBreed( Breed newBreed ) ;
    void fixCat() noexcept ;
    void setWeight( Weight newWeight ) ;
    const char* getName() const noexcept ;
    Gender getGender() const noexcept ;
    Breed getBreed() const noexcept ;
    bool isFixed() const noexcept ;
    Weight getWeight() const noexcept ;

protected:
    char        name[MAX_CATS] ;
    enum Gender gender ;
    enum Breed  breed ;
    bool        isCatFixed ;
    Weight      weight ;
private:
    void        setMemberData() ;
};

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
