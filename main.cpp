/////////////////////////////////////////////////////////////////////////////
////////
///////// University of Hawaii, College of Engineering
///////// @brief Lab 07d - Animal Farm 1 - EE 205 - Spr 2022
/////////
///////// @file main.c
///////// @version 1.0
/////////
///////// @author Brayden Suzuki <braydens@hawaii.edu>
///////// @date 21_Feb_2022
///////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "Cat.h"
#include "config.h"
#include "SinglyLinkedList.h"
using namespace std ;

int main() {
    cout << "Starting " << PROGRAM_NAME << endl ;
    SinglyLinkedList catDB ;
    catDB.push_front( new Cat( "Loki", Color::CREAM, true, Gender::MALE, 1.0 ) ) ;
    catDB.push_front( new Cat( "Milo", Color::BLACK, true, Gender::MALE, 1.1 ) ) ;
    catDB.push_front( new Cat( "Bella", Color::BROWN, true, Gender::FEMALE, 1.2 ) ) ;
    catDB.push_front( new Cat( "Kali", Color::CALICO, true, Gender::FEMALE, 1.3 ) ) ;
    catDB.push_front( new Cat( "Trin", Color::WHITE, true, Gender::FEMALE, 1.4 ) ) ;

    catDB.dump() ;
    catDB.deleteAllNodes() ;
    catDB.dump() ;
    cout << "Done with " << PROGRAM_NAME ;
    return( EXIT_SUCCESS ) ;
}