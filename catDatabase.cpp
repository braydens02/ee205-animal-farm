///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include "catDatabase.h"
#include "cstring"
using namespace std;

NumCats NUM_CATS = 0;

struct Cats catDatabase[MAX_CATS];

const char* getGender(enum Gender gender) {
    switch(gender) {
        case 0:
            return "UNKNOWN_GENDER" ;
        case 1:
            return "MALE" ;
        case 2:
            return "FEMALE" ;
    }
    return "UNKNOWN_GENDER" ;
}

const char* getBreed(enum Breed breed) {
    switch(breed) {
        case 0:
            return "UNKNOWN_BREED" ;
        case 1:
            return "MAINE_COON" ;
        case 2:
            return "MANX" ;
        case 3:
            return "SHORTHAIR" ;
        case 4:
            return "PERSIAN" ;
        case 5:
            return "SPHYNX" ;
    }
    return "UNKNOWN_BREED" ;
}

const char* getCollarColor(enum Color color) {
    switch(color) {
        case 0:
            return "UNKNOWN_COLOR" ;
        case 1:
            return "BLACK" ;
        case 2:
            return "WHITE" ;
        case 3:
            return "RED" ;
        case 4:
            return "YELLOW" ;
        case 5:
            return "ORANGE" ;
        case 6:
            return "GREEN" ;
        case 7:
            return "BLUE" ;
        case 8:
            return "PURPLE" ;
        case 9:
            return "PINK" ;
    }
    return "UNKNOWN_COLOR" ;
}