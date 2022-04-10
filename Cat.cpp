///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   08_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Cat.h"
#include <cstring>
#include <stdexcept>
using namespace std;

void Cat::setMemberData() {
    memset( name, 0, MAX_CAT_NAMES );
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = -1;
}

Cat::Cat() {
    setMemberData();
}

Cat::Cat(const char* newName, const Gender newGender, const Breed newBreed, const Weight newWeight) : Cat() {
    setName( newName ) ;
    setGender( newGender ) ;
    setBreed( newBreed ) ;
    setWeight( newWeight ) ;
}

void Cat::setName( const char* newName ) {
    validateName( newName ) ;

    memset( name, 0, MAX_CAT_NAMES ) ;

    strcpy(name, newName) ;
}

void Cat::setGender( const Gender newGender ) {
    if (gender != UNKNOWN_GENDER) throw logic_error( PROGRAM_NAME ": gender is already set") ;

    validateGender( newGender ) ;

    Cat::gender = newGender ;
}

void Cat::setBreed( const Breed newBreed ) {
    if (breed != UNKNOWN_BREED) throw logic_error( PROGRAM_NAME ": breed is already set") ;

    validateBreed( newBreed ) ;

    Cat::breed = newBreed ;
}

void Cat::setWeight( const Weight newWeight ) {
    validateWeight( newWeight );

    Cat::weight = newWeight ;
}

bool Cat::validate() {
    if (!validateName( name ) ) {
        return false ;
    }
    if (!validateGender( gender ) ) {
        return false ;
    }
    if (!validateBreed( breed ) ) {
        return false ;
    }
    if (!validateWeight( weight ) ) {
        return false ;
    }
    else {
        return true ;
    }
}

bool Cat::validateName( const char* newName ) {
    if (newName == nullptr) throw logic_error( PROGRAM_NAME ": name must not be NULL") ;

    if (strlen( newName ) <= 0) throw logic_error( PROGRAM_NAME ": name must be greater than 0") ;

    if (strlen( newName ) > MAX_CAT_NAMES) throw logic_error( PROGRAM_NAME ": name must be less than 50 characters") ;

    return true ;
}

bool Cat::validateGender( const Gender newGender ) {
    if (newGender == UNKNOWN_GENDER) throw invalid_argument( PROGRAM_NAME ": gender must be known") ;

    return true ;
}

bool Cat::validateBreed( const Breed newBreed ) {
    if (newBreed == UNKNOWN_BREED) throw invalid_argument( PROGRAM_NAME ": breed must be known") ;

    return true ;
}

bool Cat::validateWeight( const Weight newWeight ) {
    if (newWeight <= 0) throw length_error( PROGRAM_NAME ": weight must be greater than 0") ;

    return true ;
}