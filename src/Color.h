///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Color.h
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_COLOR_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_COLOR_H
#pragma once

#include <iostream>

enum class  	Color {
    UNKNOWN_COLOR =0 , BLACK , BROWN , WHITE ,
    RED , BLUE , GREEN , GINGER ,
    CREAM , CINNAMON , CALICO
} ;

inline std::ostream& operator<< (std::ostream& lhs_stream, const Color& rhs_Color) {
    switch(rhs_Color) {
        case Color::UNKNOWN_COLOR: return lhs_stream << "Unknown color" ;
        case Color::BLACK:         return lhs_stream << "Black" ;
        case Color::BROWN:         return lhs_stream << "Brown" ;
        case Color::WHITE:         return lhs_stream << "White" ;
        case Color::RED:           return lhs_stream << "Red" ;
        case Color::BLUE:          return lhs_stream << "Blue" ;
        case Color::GREEN:         return lhs_stream << "Green" ;
        case Color::GINGER:        return lhs_stream << "Ginger" ;
        case Color::CREAM:         return lhs_stream << "Cream" ;
        case Color::CINNAMON:      return lhs_stream << "Cinnamon" ;
        case Color::CALICO:        return lhs_stream << "Calico" ;
        default:
            throw std::out_of_range("The unit can't be mapped to a string") ;
    }
}

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_COLOR_H
