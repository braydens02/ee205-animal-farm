///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <cstring>
#include <iostream>
#include "catDatabase.h"
#include "config.h"
using namespace std;

void printCat(unsigned long catIndex) {
    if (catIndex > (NUM_CATS - 1)) {
        cerr << PROGRAM_NAME << ": Bad cat " << catIndex << endl;
    }
    else {
        cout << "cat index=" << catIndex << " name=" << catDatabase[catIndex].name << " gender=" << getGender(catDatabase[catIndex].gender) << " breed=" << getBreed(catDatabase[catIndex].breed) << " isFixed=" << catDatabase[catIndex].isFixed << " weight=" << catDatabase[catIndex].weight << " collarColor1=" << getCollarColor(catDatabase[catIndex].collarColor1) << " collarColor2=" << getCollarColor(catDatabase[catIndex].collarColor2) << " license=" << catDatabase[catIndex].license << endl;
    }
}

void printAllCats() {
    for (unsigned long k = 0; k < NUM_CATS; k++) {
        cout << "cat index=" << k << " name=" << catDatabase[k].name << " gender=" << getGender(catDatabase[k].gender) << " breed=" << getBreed(catDatabase[k].breed) << " isFixed=" << catDatabase[k].isFixed << " weight=" << catDatabase[k].weight << " collarColor1=" << getCollarColor(catDatabase[k].collarColor1) << " collarColor2=" << getCollarColor(catDatabase[k].collarColor2) << " license=" << catDatabase[k].license << endl;
    }
}

int findCat(const char name[]) {
    int compare;
    for (int i = 0; i < MAX_CATS; i++) {
        compare = strcmp(catDatabase[i].name, name) ;
        if (compare == 0) {
            printf("%d\n", i) ;
            return i;
            break;
        }
    }
    if (compare != 0) {
        fprintf( stderr, "%s: Cat name not found.\n", PROGRAM_NAME ) ;
        return 0;
    }
    else {
        return 0;
    }
}
