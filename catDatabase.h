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

#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Cat.h"
#include "config.h"

extern NumCats NUM_CATS ;

extern Cat* catDatabaseHeadPointer ;

extern const char* genderName( enum Gender gender ) ;
extern const char* breedName( enum Breed breed ) ;
extern const char* colorName( enum Color color ) ;

extern bool validateDatabase() ;