///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATDATABASE_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATDATABASE_H

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATDATABASE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATS (1024)
#define MAX_CAT_NAMES (50)

enum Gender {UNKNOWN_GENDER, MALE, FEMALE} ;

enum Breed {UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX} ;

enum Color {UNKNOWN_COLOR, BLACK, WHITE, RED, YELLOW, ORANGE, GREEN, BLUE, PURPLE, PINK} ;
struct Cats{
    char name[MAX_CATS] ;

    enum Gender gender ;

    enum Breed breed ;

    bool isfixed ;

    float weight ;

    enum Color collarColor1 ;

    enum Color collarColor2 ;

    unsigned long long license ;
};

typedef float Weight;
typedef unsigned long NumCats;

extern NumCats NUM_CATS ;
extern struct Cats catDatabase[MAX_CATS] ;
extern const char* getGender(enum Gender gender) ;
extern const char* getBreed(enum Breed breed) ;
extern const char* getCollarColor(enum Color color) ;
