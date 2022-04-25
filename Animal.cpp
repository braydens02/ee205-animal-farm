///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Animal.h"
#include <cassert>

const std::string Animal::KINGDOM_NAME = "Animalia";

using namespace std ;

Animal::Animal(const Weight::t_weight newMaxWeight, const std::string &newClassification,
               const std::string &newSpecies) : Node(), weight( Weight::POUND, newMaxWeight ) {
    Animal::validate() ;

    if(!Animal::validateClassification(newClassification)) {
        throw std::invalid_argument("Classification is invalid") ;
    }

    if(!Animal::validateSpecies(newSpecies)) {
        throw std::invalid_argument("Species is invalid") ;
    }

    classification = newClassification ;

    species = newSpecies ;
}

Animal::Animal(const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight,
               const std::string &newClassification, const std::string &newSpecies) : Node(), weight( newWeight, newMaxWeight ) {
    Animal::validate() ;

    if(!Animal::validateClassification(newClassification)) {
        throw std::invalid_argument("Classification is invalid") ;
    }

    if(!Animal::validateSpecies(newSpecies)) {
        throw std::invalid_argument("Species is invalid") ;
    }

    Animal::setGender(newGender) ;

    Animal::setWeight(newWeight) ;

    classification = newClassification ;

    species = newSpecies ;
}

std::string Animal::getKingdom() const noexcept {
    return KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept {
    return classification;
}

std::string Animal::getSpecies() const noexcept {
    return species;
}

Gender Animal::getGender() const noexcept {
    return gender;
}

Weight::t_weight Animal::getWeight() const noexcept {
    return weight.getWeight();
}

void Animal::setWeight(const Weight::t_weight newWeight) {
    weight.setWeight(newWeight) ;
}

bool Animal::validateClassification(const std::string &checkClassification) noexcept {
    if(checkClassification.empty()) {
        return false ;
    }

    return true ;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    if(checkSpecies.empty()) {
        return false ;
    }

    return true ;
}

void Animal::setGender(const Gender newGender) {
    if(gender != Gender::UNKNOWN_GENDER) {
        throw std::invalid_argument("Gender is already set") ;
    }

    gender = newGender ;
}

Animal::~Animal() {
}

void Animal::dump() const noexcept {
    Node::dump();

    Animal::validate() ;

    FORMAT_LINE_FOR_DUMP( "Animal", "this" ) << this << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "kingdom" ) << getKingdom() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "classification" ) << getClassification() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "species" ) << getSpecies() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "gender" ) << getGender() << endl ;
    FORMAT_LINE_FOR_DUMP( "Animal", "weight" ) << weight << endl ;
}

bool Animal::validate() const noexcept {
    Animal::validateClassification( Animal::getClassification() ) ;
    Animal::validateSpecies( Animal::getSpecies() ) ;
    assert(!Animal::getKingdom().empty()) ;
    assert(Node::validate()) ;
    assert(weight.validate()) ;
    return true ;
}
