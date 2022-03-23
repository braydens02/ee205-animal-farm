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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "catDatabase.h"
#include "config.h"

void printCat(unsigned long catIndex) {
    if (catIndex > (NUM_CATS - 1)) {
        fprintf( stderr, "%s: Bad cat [%lu]\n", PROGRAM_NAME, catIndex );
    }
    else {
        printf("cat index = [%lu] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f] collarColor1=[%s] collarColor2=[%s] license=[%llu]\n", catIndex, catDatabase[catIndex].name, getGender(catDatabase[catIndex].gender), getBreed(catDatabase[catIndex].breed), catDatabase[catIndex].isfixed, catDatabase[catIndex].weight, getCollarColor(catDatabase[catIndex].collarColor1), getCollarColor(catDatabase[catIndex].collarColor2), catDatabase[catIndex].license );
    }
}

void printAllCats() {
    for (unsigned long k = 0; k < NUM_CATS; k++) {
        printf("cat index = [%lu] name=[%s] gender=[%s] breed=[%s] isFixed=[%d] weight=[%f] collarColor1=[%s] collarColor2=[%s] license=[%llu]\n", k, catDatabase[k].name, getGender(catDatabase[k].gender), getBreed(catDatabase[k].breed), catDatabase[k].isfixed, catDatabase[k].weight, getCollarColor(catDatabase[k].collarColor1), getCollarColor(catDatabase[k].collarColor2), catDatabase[k].license );
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
