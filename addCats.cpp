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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catDatabase.h"
#include "addCats.h"
#include "config.h"

int addCat(const char name[], enum Gender gender, enum Breed breed, bool isfixed, float weight, enum Color collarColor1, enum Color collarColor2, unsigned long long license) {

    int result;
    unsigned long catIndex;

    for (int i = 0; i < MAX_CATS; i++) {
        result = strcmp(catDatabase[i].name, name);
        if (result == 0) {
            break;
        }
    }

    if (NUM_CATS == MAX_CATS) {
        fprintf( stderr, "%s: Too many cats in database.\n", PROGRAM_NAME ) ;
        return 0;
    }
    if (strlen(name) <= 0) {
        fprintf( stderr, "%s: Cat's name cannot be empty.\n", PROGRAM_NAME ) ;
        return 0;
    }
    if (strlen(name) > MAX_CAT_NAMES) {
        fprintf( stderr, "%s: Cat's name cannot be greater than 30 characters.\n", PROGRAM_NAME ) ;
        return 0;
    }
    if (result == 0) {
        fprintf( stderr, "%s: Name must be unique.\n", PROGRAM_NAME ) ;
        return 0;
    }
    if (weight <= 0) {
        fprintf( stderr, "%s: Weight must be greater than 0.\n", PROGRAM_NAME ) ;
        return 0;
    }
    else {
        for (int j = 0; j < MAX_CAT_NAMES; j++) {
            catDatabase[NUM_CATS].name[j] = name[j];
        }
        catDatabase[NUM_CATS].gender = gender;
        catDatabase[NUM_CATS].breed = breed;
        catDatabase[NUM_CATS].isfixed = isfixed;
        catDatabase[NUM_CATS].weight = weight;
        catDatabase[NUM_CATS].collarColor1 = collarColor1;
        catDatabase[NUM_CATS].collarColor2 = collarColor2;
        catDatabase[NUM_CATS].license = license;
        NUM_CATS = NUM_CATS + 1;
        catIndex = NUM_CATS - 1;
        return catIndex;
    }
}