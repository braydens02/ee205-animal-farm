///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_UPDATECATS_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_UPDATECATS_H

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_UPDATECATS_H

extern void updateCatName(unsigned long catIndex, const char new_name[]);
extern void fixCat(unsigned long catIndex);
extern void updateCatWeight(unsigned long catIndex, float new_weight);
extern void updateCatCollar1(unsigned long catIndex, enum Color newCollarColor1 );
extern void updateCatCollar2(unsigned long catIndex, enum Color newCollarColor2 );
extern void updateLicense(unsigned long catIndex, unsigned long long newLicense );