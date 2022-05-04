///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_ANIMAL_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_ANIMAL_H

#pragma once

#include <string>

#include "config.h"
#include "Node.h"
#include "Gender.h"
#include "Weight.h"

/// A class that encompasses all Animals on the farm.
///
/// This class should be the parent class of all of the Animals on the farm.
/// It contains 1 abstract method `speak()` that each Animal must implement
/// before it can be instantiated.
///
/// Animals understand things I don't know -- and they know languages which are not made of words.”
///
/// @see https://en.wikipedia.org/wiki/Animal
/// @see https://en.wikipedia.org/wiki/Taxonomy_(biology)
class Animal : public Node {
public:   //////////////////////// Constants ///////////////////////////////////
    static const std::string KINGDOM_NAME;  ///< The scientific name of the Animal Kingdom.

private:  ///////////////////// Member Variables //////////////////////////////
    std::string species;                     ///< The Animal's biological species
    std::string classification;              ///< The Animal's biological classification
    Gender gender = Gender::UNKNOWN_GENDER;  ///< The Animal's gender
    Weight weight;                           ///< The weight of the Animal

public:   /////////////////////// Constructors ////////////////////////////////
    /// Create an Animal with the *minimum* required fields
    Animal( const Weight::t_weight newMaxWeight
            ,const std::string&     newClassification
            ,const std::string&     newSpecies
    );

    /// Create an Animal, populating *all* of the member variables
    Animal( const Gender           newGender
            ,const Weight::t_weight newWeight
            ,const Weight::t_weight newMaxWeight
            ,const std::string&     newClassification
            ,const std::string&     newSpecies
    );

    virtual ~Animal() ;

public:   ///////////////////// Getters & Setters /////////////////////////////
    std::string getKingdom() const noexcept;         ///< Get the kingdom, which is `Animalia`
    std::string getClassification() const noexcept;  ///< Get the classification
    std::string getSpecies() const noexcept;         ///< Get the species

    Gender getGender() const noexcept;  ///< Get the Animal's Gender

    Weight::t_weight getWeight() const noexcept;         ///< Get the Animal's Weight
    void setWeight( const Weight::t_weight newWeight );  ///< Set the Animal's Weight

public:  /////////////////////// Static Public Methods /////////////////////////
    // Static methods are `const` by default
    static bool validateClassification( const std::string& checkClassification ) noexcept;  ///< Verify the biological classification is valid
    static bool validateSpecies( const std::string& checkSpecies ) noexcept;                ///< Verify the biological species is valid

protected:  ////////////////////// Protected Methods ///////////////////////////
    void setGender( const Gender newGender);   ///< Set the Animal's Gender

public:   ////////////////////// Abstract Methods //////////////////////////////
    virtual std::string speak() const noexcept = 0;  ///< Ask the Animal to say something.  This method is virtual and abstract.

public:   ////////////////////////// Methods //////////////////////////////////
    void dump() const noexcept override ;       ///< Output the contents of this object
    bool validate() const noexcept override;   ///< Check to see if the Animal object is valid
};

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_ANIMAL_H
