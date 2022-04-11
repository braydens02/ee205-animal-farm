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

/*
enum Color {UNKNOWN_COLOR, BLACK, WHITE, RED, YELLOW, ORANGE, GREEN, BLUE, PURPLE, PINK} ;
 */

class Cat {
public:
    Cat() ; // constructor initializes invalid cat
    Cat(const char *newName, Gender newGender, Breed newBreed, Weight newWeight) ;
    Cat* next ;
    bool print() const noexcept ;  // formatted print function
    bool validate() const noexcept ; // returns true if cat is valid, false if it isn't
    static bool validateName( const char* newName ) ;
    static bool validateGender( Gender newGender ) ;
    static bool validateBreed( Breed newBreed ) ;
    static bool validateWeight( Weight newWeight ) ;
    void setName( const char *newName ) ; // set name of cat
    void setGender( Gender newGender ) ; // set gender of cat
    void setBreed( Breed newBreed ) ; // set breed of cat
    void fixCat() noexcept ; // turns bool value isCatFixed to true
    void setWeight( Weight newWeight ) ; // set weight of cat
    const char* getName() const noexcept ; // returns name of cat
    Gender getGender() const noexcept ; // returns gender of cat
    Breed getBreed() const noexcept ; // returns breed of cat
    bool isFixed() const noexcept ; // returns whether cat is fixed
    Weight getWeight() const noexcept ; // returns weight of cat

protected:
    char        name[MAX_CATS] ;
    enum Gender gender ;
    enum Breed  breed ;
    bool        isCatFixed ;
    Weight      weight ;
private:
    void        setMemberData() ; // function initializes all data members to be invalid
};

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
