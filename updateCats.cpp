///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "catDatabase.h"
#include "config.h"

void updateCatName(unsigned long catIndex, const char new_name[]) {

    char old_name[MAX_CAT_NAMES];

    int result;

    for (int i = 0; i < MAX_CATS; i++) {
        result = strcmp(catDatabase[i].name, new_name);
        if (result == 0) {
            break;
        }
    }

    if (strlen(new_name) <= 0) {
        fprintf( stderr, "%s: Cat's name cannot be empty.\n", PROGRAM_NAME ) ;
    }
    if (strlen(new_name) > MAX_CAT_NAMES) {
        fprintf( stderr, "%s: Cat's name cannot be greater than 30 characters.\n", PROGRAM_NAME ) ;
    }
    if (result == 0) {
        fprintf( stderr, "%s: Name must be unique.\n", PROGRAM_NAME ) ;
    }
    else {
        for (int l = 0; l < MAX_CAT_NAMES; l++) {
            old_name[l] = catDatabase[catIndex].name[l];
        }
        for (int m = 0; m < MAX_CAT_NAMES; m++) {
            catDatabase[catIndex].name[m] = new_name[m];
        }
        printf("cat index = [%lu] previous name = [%s] new name = [%s]\n", catIndex, old_name, catDatabase[catIndex].name);
    }
}

void fixCat(unsigned long catIndex) {
    if (catDatabase[catIndex].isfixed == 1) {
        fprintf( stderr, "%s: Cat is already fixed.\n", PROGRAM_NAME ) ;
    }
    else {
        catDatabase[catIndex].isfixed = 1;
        printf("%s is now fixed.\n", catDatabase[catIndex].name);
    }
}

void updateCatWeight(unsigned long catIndex, float new_weight) {
    float old_weight;
    if (new_weight <= 0) {
        fprintf( stderr, "%s: Weight must be greater than 0.\n", PROGRAM_NAME ) ;
    }
    else {
        old_weight = catDatabase[catIndex].weight;
        catDatabase[catIndex].weight = new_weight;
        printf("cat index: [%lu] name: [%s] previous weight: [%f] new weight: [%f]\n", catIndex, catDatabase[catIndex].name, old_weight, new_weight);
    }
}

void updateCatCollar1(unsigned long catIndex, enum Color newCollarColor1) {
    enum Color oldCollarColor1 ;
    oldCollarColor1 = catDatabase[catIndex].collarColor1 ;
    catDatabase[catIndex].collarColor1 = newCollarColor1 ;
    printf("cat index: [%lu] name: [%s] previous collarColor: [%s] new collarColor: [%s]\n", catIndex, catDatabase[catIndex].name, getCollarColor(oldCollarColor1), getCollarColor(newCollarColor1) ) ;
}

void updateCatCollar2(unsigned long catIndex, enum Color newCollarColor2) {
    enum Color oldCollarColor2 ;
    oldCollarColor2 = catDatabase[catIndex].collarColor2 ;
    catDatabase[catIndex].collarColor2 = newCollarColor2 ;
    printf("cat index: [%lu] name: [%s] previous collarColor: [%s] new collarColor: [%s]\n", catIndex, catDatabase[catIndex].name, getCollarColor(oldCollarColor2), getCollarColor(newCollarColor2) ) ;
}

void updateLicense(unsigned long catIndex, unsigned long long newLicense) {
    unsigned long long oldLicense ;
    oldLicense = catDatabase[catIndex].license ;
    catDatabase[catIndex].license = newLicense ;
    printf("cat index: [%lu] name: [%s] previous license: [%llu] new license: [%llu]\n", catIndex, catDatabase[catIndex].name, oldLicense, newLicense) ;
}