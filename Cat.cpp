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
#include "catDatabase.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

// constructor, initializes an instance of cat
void Cat::setMemberData() {
    memset( name, 0, MAX_CAT_NAMES );
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isCatFixed = false;
    weight = -1;
    next = nullptr ;
}

Cat::Cat() {
    setMemberData() ;
}

// function sets all the data member values when called
Cat::Cat(const char* newName, const Gender newGender, const Breed newBreed, const Weight newWeight) : Cat() {
    setName( newName ) ;
    setGender( newGender ) ;
    setBreed( newBreed ) ;
    setWeight( newWeight ) ;
}

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

// print function to print out the information of a cat in a specific way
bool Cat::print() const noexcept {
    assert( validate() ) ;

    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ') ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" ) << getName() << endl ;
    FORMAT_LINE( "Cat", "gender" ) << genderName( getGender() ) << endl ;
    FORMAT_LINE( "Cat", "breed" ) << breedName( getBreed() ) << endl ;
    FORMAT_LINE( "Cat", "isFixed" ) << isFixed() << endl ;
    FORMAT_LINE( "Cat", "weight" ) << getWeight() << endl ;

    return true ;
}

// checks validity of new name before setting name to 0's to "clear" the space
// then copies the new name to the destination that was just cleared
void Cat::setName( const char* newName ) {
    validateName( newName ) ;

    memset( name, 0, MAX_CAT_NAMES ) ;

    strcpy(name, newName) ;
}

// checks to make sure the new gender is known and valid before assigning the value to Cat::gender
void Cat::setGender( const Gender newGender ) {
    if (gender != UNKNOWN_GENDER) throw logic_error( PROGRAM_NAME ": gender is already set") ;

    validateGender( newGender ) ;

    Cat::gender = newGender ;
}

// checks to make sure new breed is known and valid before assigning the value to Cat::breed
void Cat::setBreed( const Breed newBreed ) {
    if (breed != UNKNOWN_BREED) throw logic_error( PROGRAM_NAME ": breed is already set") ;

    validateBreed( newBreed ) ;

    Cat::breed = newBreed ;
}

// changes value of bool isCatFixed from false to true, isCatFixed is always false when cat is created
void Cat::fixCat() noexcept {
    Cat::isCatFixed = true ;
}

// checks if weight is valid before assigning value to Cat::weight
void Cat::setWeight( const Weight newWeight ) {
    validateWeight( newWeight );

    Cat::weight = newWeight ;
}

// runs all validate functions in order to check if cat is valid
// returns true if it is and false if it isn't
bool Cat::validate() const noexcept {
    try {
        validateName( name ) ;
        validateGender( gender ) ;
        validateBreed( breed ) ;
        validateWeight( weight ) ;
    } catch (exception const& e) {
        cout << e.what() << endl ;
        return false ;
    }

    return true ;
}

// name is valid if it isn't null, if the # of characters is greater than 0, and less than the max # of characters
// max number of characters is defined as MAX_CAT_NAMES
bool Cat::validateName( const char* newName ) {
    if (newName == nullptr) throw logic_error( PROGRAM_NAME ": name must not be NULL") ;

    if (strlen( newName ) <= 0) throw logic_error( PROGRAM_NAME ": name must be greater than 0") ;

    if (strlen( newName ) > MAX_CAT_NAMES) throw logic_error( PROGRAM_NAME ": name must be less than 50 characters") ;

    return true ;
}

// checks if gender is known
bool Cat::validateGender( const Gender newGender ) {
    if (newGender == UNKNOWN_GENDER) throw invalid_argument( PROGRAM_NAME ": gender must be known") ;

    return true ;
}

// checks if breed is known
bool Cat::validateBreed( const Breed newBreed ) {
    if (newBreed == UNKNOWN_BREED) throw invalid_argument( PROGRAM_NAME ": breed must be known") ;

    return true ;
}

// checks if weight is greater than 0
bool Cat::validateWeight( const Weight newWeight ) {
    if (newWeight <= 0) throw length_error( PROGRAM_NAME ": weight must be greater than 0") ;

    return true ;
}

const char *Cat::getName() const noexcept {
    return name ;
}

Gender Cat::getGender() const noexcept {
    return gender ;
}

Breed Cat::getBreed() const noexcept {
    return breed ;
}

bool Cat::isFixed() const noexcept {
    return isCatFixed ;
}

Weight Cat::getWeight() const noexcept {
    return weight ;
}