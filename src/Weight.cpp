///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std ;

static const std::string POUND_LABEL = "Pound" ;
static const std::string KILO_LABEL = "Kilo" ;
static const std::string SLUG_LABEL = "Slug" ;

const float Weight::UNKNOWN_WEIGHT = 0 ;
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;

std::ostream& operator<<( ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << POUND_LABEL ;
        case Weight::KILO: return lhs_stream << KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << SLUG_LABEL ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}

Weight::Weight() noexcept {
    Weight::bIsKnown = false ;
    Weight::bHasMax = false ;
    Weight::unitOfWeight = POUND ;
    Weight::weight = UNKNOWN_WEIGHT ;
    Weight::maxWeight = UNKNOWN_WEIGHT ;
}

Weight::Weight(float newWeight) {
    Weight::bHasMax = false ;
    Weight::unitOfWeight = POUND ;
    setWeight( newWeight ) ;
    Weight::maxWeight = UNKNOWN_WEIGHT ;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    Weight::bIsKnown = false ;
    Weight::bHasMax = false ;
    Weight::unitOfWeight = newUnitOfWeight ;
    Weight::weight = UNKNOWN_WEIGHT ;
    Weight::maxWeight = UNKNOWN_WEIGHT ;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    Weight::bHasMax = false ;
    Weight::unitOfWeight = newUnitOfWeight ;
    setWeight( newWeight ) ;
    Weight::maxWeight = UNKNOWN_WEIGHT ;
}

Weight::Weight(float newWeight, float newMaxWeight) {
    Weight::unitOfWeight = POUND ;
    setWeight( newWeight ) ;
    setMaxWeight( newMaxWeight ) ;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    Weight::bIsKnown = false ;
    Weight::unitOfWeight = newUnitOfWeight ;
    Weight::weight = UNKNOWN_WEIGHT ;
    setMaxWeight( newMaxWeight ) ;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    Weight::unitOfWeight = newUnitOfWeight ;
    setWeight( newWeight ) ;
    setMaxWeight( newMaxWeight ) ;
}

bool Weight::isWeightKnown() const noexcept {
    return Weight::bIsKnown ;
}

bool Weight::hasMaxWeight() const noexcept {
    return Weight::bHasMax ;
}

float Weight::getWeight() const noexcept {
    return Weight::weight ;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    float toValue ;
    toValue = convertWeight( Weight::weight, Weight::unitOfWeight, weightUnits ) ;
    return toValue ;
}

float Weight::getMaxWeight() const noexcept {
    return Weight::maxWeight ;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return Weight::unitOfWeight ;
}

void Weight::setWeight(float newWeight) {
    if(isWeightValid( newWeight )) {
        Weight::weight = newWeight ;
        Weight::bIsKnown = true ;
    }

    else{
        throw out_of_range("Weight is not valid") ;
    }
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    if(isWeightValid( newWeight )) {
        Weight::weight = newWeight ;
        Weight::unitOfWeight = weightUnits ;
        Weight::bIsKnown = true ;
    }

    else{
        throw out_of_range("Weight is not valid.") ;
    }
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    if( checkWeight <= 0 ) {
        return false ;
    }

    if( Weight::maxWeight != UNKNOWN_WEIGHT && checkWeight > Weight::maxWeight ) {
        return false ;
    }

    else{
        return true ;
    }
}

bool Weight::validate() const noexcept {
    if( 0 >= Weight::weight || Weight::weight > Weight::maxWeight ) {
        return false ;
    }

    if( 0 > Weight::maxWeight || Weight::maxWeight < Weight::weight ) {
        return false ;
    }

    else{
        return true ;
    }
}

#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

void Weight::dump() const noexcept {
    cout << setw(46) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ') ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight", "this" ) << &weight << endl ;
    FORMAT_LINE( "Weight", "isKnown" ) << isWeightKnown() << endl ;
    FORMAT_LINE( "Weight", "weight" ) << getWeight() << endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << getWeightUnit() << endl ;
    FORMAT_LINE( "Weight", "hasMax" ) << hasMaxWeight() << endl ;
    FORMAT_LINE( "Weight", "maxWeight" ) << getMaxWeight() << endl ;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

Weight &Weight::operator+=(t_weight rhs_addToWeight) {
    Weight *weightValue ;
    weightValue->weight += rhs_addToWeight ;
    return *weightValue ;
}

float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND ;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND ;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND ;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    float toValue ;
    if( fromUnit == POUND ) {
        switch(toUnit) {
            case SLUG:
                toValue = fromPoundToSlug( fromWeight ) ;
                return toValue ;
            case KILO:
                toValue = fromPoundToKilogram( fromWeight ) ;
                return toValue ;
            case POUND:
                toValue = fromWeight ;
                return toValue ;
        }
    }

    if( fromUnit == KILO ) {
        switch(toUnit) {
            case SLUG:
                toValue = fromPoundToSlug( fromKilogramToPound( fromWeight ) ) ;
                return toValue ;
            case POUND:
                toValue = fromKilogramToPound( fromWeight ) ;
                return toValue ;
            case KILO:
                toValue = fromWeight ;
                return toValue ;
        }
    }

    if( fromUnit == SLUG ) {
        switch(toUnit) {
            case KILO:
                toValue = fromPoundToKilogram( fromSlugToPound( fromWeight ) ) ;
                return toValue ;
            case POUND:
                toValue = fromSlugToPound( fromWeight ) ;
                return toValue ;
            case SLUG:
                toValue = fromWeight ;
                return toValue ;
        }
    }
    return -1 ;
}

void Weight::setMaxWeight(float newMaxWeight) {
    if( newMaxWeight <= 0 || (Weight::weight != UNKNOWN_WEIGHT && newMaxWeight < Weight::weight) ) {
        throw out_of_range("Max weight must not be less than previously set weight") ;
    }

    else{
        Weight::maxWeight = newMaxWeight ;
        Weight::bHasMax = true ;
    }
}

std::ostream &operator<<(ostream &lhs_stream, const Weight &rhs_Weight) {
    stringstream string ;
    if(!rhs_Weight.isWeightKnown()) {
        string << "Unknown" ;
    }

    if(!rhs_Weight.isWeightKnown() && rhs_Weight.hasMaxWeight()) {
        string << " out of " << rhs_Weight.getMaxWeight() << " " << rhs_Weight.getWeightUnit() ;
    }

    if(rhs_Weight.isWeightKnown()) {
        string << rhs_Weight.getWeight() ;
    }

    if(rhs_Weight.isWeightKnown() && !rhs_Weight.hasMaxWeight()) {
        string << rhs_Weight.getWeightUnit() ;
    }

    if(rhs_Weight.isWeightKnown() && rhs_Weight.hasMaxWeight()) {
        string << " out of " << rhs_Weight.getMaxWeight() << " " << rhs_Weight.getWeightUnit() ;
    }

    if((rhs_Weight.hasMaxWeight() && rhs_Weight.getMaxWeight() > 1 ) || (!rhs_Weight.hasMaxWeight() && rhs_Weight.getWeight() > 1) ) {
        string << "s" ;
    }

    return lhs_stream << string.str() ;
}