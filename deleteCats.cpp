///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "catDatabase.h"

void deleteAllCats() {
    for (int i = 0; i < MAX_CATS; i++) {
        for (int j = 0; j < MAX_CAT_NAMES; j++) {
            catDatabase[i].name[j] = 0;
        }
        catDatabase[i].gender = UNKNOWN_GENDER;
        catDatabase[i].breed = UNKNOWN_BREED;
        catDatabase[i].isfixed = 0;
        catDatabase[i].weight = 0;
        catDatabase[i].collarColor1 = UNKNOWN_COLOR;
        catDatabase[i].collarColor2 = UNKNOWN_COLOR;
        catDatabase[i].license = 0;
    }
}

void deleteCat(unsigned long index) {
    for (int j = 0; j < MAX_CAT_NAMES; j++) {
        catDatabase[index].name[j] = 0;
    }
    catDatabase[index].gender = UNKNOWN_GENDER;
    catDatabase[index].breed = UNKNOWN_BREED;
    catDatabase[index].isfixed = 0;
    catDatabase[index].weight = 0;
    catDatabase[index].collarColor1 = UNKNOWN_COLOR;
    catDatabase[index].collarColor2 = UNKNOWN_COLOR;
    catDatabase[index].license = 0;
}
