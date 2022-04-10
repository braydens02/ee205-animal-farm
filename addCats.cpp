///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <cstring>
#include <iostream>
#include "catDatabase.h"
#include "addCats.h"
#include "config.h"
using namespace std;

int addCat(const char name[], enum Gender gender, enum Breed breed, bool isfixed, Weight weight, enum Color collarColor1, enum Color collarColor2, unsigned long long license) {

    unsigned long catIndex;

    if (NUM_CATS == MAX_CATS) {
        cerr << PROGRAM_NAME << ": Too many cats in database." << endl;
        return 0;
    }
    if (strlen(name) <= 0) {
        cerr << PROGRAM_NAME << ": Cat's name cannot be empty." << endl;
        return 0;
    }
    if (strlen(name) > MAX_CAT_NAMES) {
        cerr << PROGRAM_NAME << ": Cat's name cannot be greater than 30 characters." << endl;
        return 0;
    }
    if (weight <= 0) {
        cerr << PROGRAM_NAME << ": Weight must be greater than 0." << endl;
        return 0;
    }
    else {
        for (int j = 0; j < MAX_CAT_NAMES; j++) {
            catDatabase[NUM_CATS].name[j] = name[j];
        }
        catDatabase[NUM_CATS].gender = gender;
        catDatabase[NUM_CATS].breed = breed;
        catDatabase[NUM_CATS].isFixed = isfixed;
        catDatabase[NUM_CATS].weight = weight;
        catDatabase[NUM_CATS].collarColor1 = collarColor1;
        catDatabase[NUM_CATS].collarColor2 = collarColor2;
        catDatabase[NUM_CATS].license = license;
        NUM_CATS = NUM_CATS + 1;
        catIndex = NUM_CATS - 1;
        return catIndex;
    }
}