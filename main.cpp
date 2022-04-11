/////////////////////////////////////////////////////////////////////////////
////////
///////// University of Hawaii, College of Engineering
///////// @brief Lab 07d - Animal Farm 1 - EE 205 - Spr 2022
/////////
///////// @file main.c
///////// @version 1.0
/////////
///////// @author Brayden Suzuki <braydens@hawaii.edu>
///////// @date 21_Feb_2022
///////////////////////////////////////////////////////////////////////////////////
#include <cstring>
#include <iostream>
#include <cassert>
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"
#include "Cat.h"
using namespace std ;

int main() {

#ifdef NULL
    Cat testCat = Cat() ;
    assert( testCat.getName() != nullptr ) ;
    assert( strcmp(testCat.getName(), "") == 0 ) ;
    assert( testCat.getGender() == UNKNOWN_GENDER ) ;
    assert( testCat.getBreed() == UNKNOWN_BREED ) ;
    assert( testCat.getWeight() == -1 ) ;
    assert( testCat.isFixed() == false ) ;
    assert( !testCat.validate() ) ;

    try {
        testCat.setName(nullptr ) ;
        assert( false ) ;
    }
 catch ( exception const &e) {}

    try {
        testCat.setName( "" ) ;
        assert( false ) ;
    }
    catch ( exception const &e) {}

    testCat.setName( "1" ) ;

#define MAX_CAT_NAMES1 "01234567890123456789012345678901234456789123456789"
#define ILLEGAL_NAME "012345678901234567890123456789012344567891234567890"

    testCat.setName( MAX_CAT_NAMES1 ) ;

    try {
        testCat.setName( ILLEGAL_NAME ) ;
        assert( false ) ;
    }
    catch ( exception const &e) {}

    testCat.setGender( MALE ) ;

    try {
        testCat.setGender( FEMALE ) ;
        assert( false ) ;
    }
    catch ( exception const &e) {}

    testCat.setBreed( MAINE_COON ) ;

    try {
        testCat.setBreed( SPHYNX ) ;
        assert( false ) ;
    }
    catch ( exception const &e) {}

    testCat.isFixed() ;
    testCat.fixCat() ;
    testCat.isFixed() ;

    try {
        testCat.setWeight( 0 ) ;
        assert( false ) ;
    }
    catch ( exception const &e) {}

    testCat.setWeight( 1.0/1024 ) ;

    assert( testCat.validate() ) ;

    try {
        addCat( new Cat( "Illegal", UNKNOWN_GENDER, PERSIAN, 1.0 )) ;
        assert( false ) ;
    }
    catch ( exception const &e) {}

    try {
        addCat( new Cat( "Illegal", MALE, UNKNOWN_BREED, 1.0 )) ;
        assert( false ) ;
    }
    catch ( exception const &e) {}

    try {
        addCat( new Cat( "Illegal", MALE, PERSIAN, -1 )) ;
        assert( false ) ;
    }
    catch ( exception const &e) {}

    addCat(new Cat("Bella", FEMALE, MAINE_COON, 1.2));

    Cat *Bella = findCatbyName( "Bella" ) ;

    assert( Bella != nullptr ) ;

    Cat *Belinda = findCatbyName( "Belinda" ) ;

    assert( Belinda == nullptr ) ;

    assert( deleteCat( Bella )) ;

#endif

    cout << "Starting Animal Farm 2" << endl;

    addCat(new Cat("Loki", MALE, PERSIAN, 1.0));
    addCat(new Cat("Milo", MALE, MANX, 1.1));
    addCat(new Cat("Bella", FEMALE, MAINE_COON, 1.2));
    addCat(new Cat("Kali", FEMALE, SHORTHAIR, 1.3));
    addCat(new Cat("Trin", FEMALE, MANX, 1.4));
    addCat(new Cat("Chili", MALE, SHORTHAIR, 1.5));

    printAllCats() ;

    deleteAllCats() ;

    printAllCats() ;

    cout << "Done with Animal Farm 2" << endl;

}