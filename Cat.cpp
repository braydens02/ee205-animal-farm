///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   08_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Cat.h"
#include "Mammal.h"
#include <stdexcept>
#include <iostream>
#include <cassert>

using namespace std;

const std::string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;

std::string Cat::getName() const noexcept {
    return name ;
}

void Cat::setName(const string &newName) {
    name = newName ;
}

bool Cat::isFixed() const noexcept {
    return isCatFixed ;
}

void Cat::fixCat() noexcept {
    isCatFixed = true ;
}

std::string Cat::speak() const noexcept {
    return "Meow";
}

void Cat::dump() const noexcept {
    assert( validate() ) ;

    Mammal::dump() ;

    FORMAT_LINE_FOR_DUMP("Cat", "name") << getName() << endl ;
    FORMAT_LINE_FOR_DUMP("Cat", "isCatFixed") << isFixed() << endl ;
}

bool Cat::validate() const noexcept {
    Animal::validate() ;

    validateName( getName() ) ;

    return true ;
}

bool Cat::validateName(const string &newName) {
    if (newName.empty()) throw logic_error( PROGRAM_NAME ": name must not be NULL") ;

    return true ;
}
