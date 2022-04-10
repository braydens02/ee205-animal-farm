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

using namespace std;

NumCats NUM_CATS = 0 ;

Cat* catDatabaseHeadPointer = nullptr ;

const char* genderName(enum Gender gender) {
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

const char* breedName(enum Breed breed) {
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

const char* colorName(enum Color color) {
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

bool validateDatabase() {
    for (Cat *iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next) {
        if (!iCat->validate()) {
            return false;
        }
    }

    return true;
}