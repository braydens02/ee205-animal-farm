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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"

int main() {
    addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101 ) ;
    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 ) ;
    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103 ) ;
    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104 ) ;
    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105 ) ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) ;
    printAllCats();

    int kali = findCat( "Kali" ) ;
    int bella = findCat( "Bella" ) ;
    updateCatName( kali, "Chili" ) ; // this should fail
    printCat( kali );
    updateCatName( kali, "Capulet" ) ;
    updateCatWeight( kali, 9.9 ) ;
    fixCat( kali ) ;
    printCat( kali );

    printAllCats();

    deleteCat(3);
    printAllCats();

    updateCatCollar1( bella, BLUE ) ;
    updateCatCollar2( bella, WHITE ) ;
    updateLicense( bella, 111 ) ;
    printAllCats() ;
}