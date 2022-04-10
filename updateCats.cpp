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
#include <cstring>
#include <iostream>
#include "catDatabase.h"
#include "config.h"
using namespace std;

/*
void updateCatName(unsigned long catIndex, const char new_name[]) {

    char old_name[MAX_CAT_NAMES];

    if (strlen(new_name) <= 0) {
        cerr << PROGRAM_NAME << ": Cat's name cannot be empty." << endl;
    }
    if (strlen(new_name) > MAX_CAT_NAMES) {
        cerr << PROGRAM_NAME << ": Cat's name cannot be greater than 30 characters." << endl;
    }
    else {
        for (int l = 0; l < MAX_CAT_NAMES; l++) {
            old_name[l] = catDatabase[catIndex].name[l];
        }
        for (int m = 0; m < MAX_CAT_NAMES; m++) {
            catDatabase[catIndex].name[m] = new_name[m];
        }
        cout << "cat index:" << catIndex << " previous name:" << old_name << " new name:" << catDatabase[catIndex].name << endl;
    }
}

void fixCat(unsigned long catIndex) {
    if (catDatabase[catIndex].isFixed == 1) {
        cerr << PROGRAM_NAME << ": Cat is already fixed." << endl;
    }
    else {
        catDatabase[catIndex].isFixed = 1;
        cout << catDatabase[catIndex].name << " is now fixed." << endl;
    }
}

void updateCatWeight(unsigned long catIndex, Weight new_weight) {
    float old_weight;
    if (new_weight <= 0) {
        cerr << PROGRAM_NAME << ": Weight must be greater than 0." << endl;
    }
    else {
        old_weight = catDatabase[catIndex].weight;
        catDatabase[catIndex].weight = new_weight;
        cout << "cat index:" << catIndex << " name:" << catDatabase[catIndex].name << " previous weight:" << old_weight << " new weight:" << new_weight << endl;
    }
}

void updateCatCollar1(unsigned long catIndex, enum Color newCollarColor1) {
    enum Color oldCollarColor1 ;
    oldCollarColor1 = catDatabase[catIndex].collarColor1 ;
    catDatabase[catIndex].collarColor1 = newCollarColor1 ;
    cout << "cat index:" << catIndex << " name:" << catDatabase[catIndex].name << " previous collarColor:" << getCollarColor(oldCollarColor1) << " new collarColor:" << getCollarColor(newCollarColor1) << endl;
}

void updateCatCollar2(unsigned long catIndex, enum Color newCollarColor2) {
    enum Color oldCollarColor2 ;
    oldCollarColor2 = catDatabase[catIndex].collarColor2 ;
    catDatabase[catIndex].collarColor2 = newCollarColor2 ;
    cout << "cat index:" << catIndex << " name:" << catDatabase[catIndex].name << " previous collarColor:" << getCollarColor(oldCollarColor2) << " new collarColor:" << getCollarColor(newCollarColor2) << endl;
}

void updateLicense(unsigned long catIndex, unsigned long long newLicense) {
    unsigned long long oldLicense ;
    oldLicense = catDatabase[catIndex].license ;
    catDatabase[catIndex].license = newLicense ;
    cout << "cat index:" << catIndex << " name:" << catDatabase[catIndex].name << " previous license:" << oldLicense << " new license:" << newLicense << endl;
}
 */