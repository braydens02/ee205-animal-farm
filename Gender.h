///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Gender.h
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_GENDER_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_GENDER_H
#pragma once

#include <iostream>

enum class  	Gender { UNKNOWN_GENDER =0 , MALE , FEMALE } ;

inline std::ostream& operator<< (std::ostream& lhs_stream, const Gender& rhs_Gender) {
    switch(rhs_Gender) {
        case Gender::UNKNOWN_GENDER: return lhs_stream << "UNKNOWN_GENDER" ;
        case Gender::MALE:           return lhs_stream << "MALE" ;
        case Gender::FEMALE:         return lhs_stream << "FEMALE" ;
        default:
            throw std::out_of_range("The unit can’t be mapped to a string") ;
    }
}

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_GENDER_H
