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
#include <cassert>
#include "addCats.h"
using namespace std;

// adds a new instance of cat
bool addCat(Cat* newCat) {
    assert( newCat != nullptr ) ;

    newCat -> validate() ;

    newCat -> next = catDatabaseHeadPointer ;

    catDatabaseHeadPointer = newCat ;

    NUM_CATS++ ;

    assert( validateDatabase() ) ;

    return true ;
}