///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.h
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_SINGLYLINKEDLIST_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_SINGLYLINKEDLIST_H

#pragma once

#include "List.h"

/// A generic SinglyLinkedList collection class.
///

class SinglyLinkedList : public List {
public:  ///////////////////////// Public Constructors /////////////////////////
    SinglyLinkedList();        ///< Make a new SinglyLinkedList

public:  /////////////////////////// Public Methods ////////////////////////////
    void  push_front( Node* newNode ) ;  ///< Insert `newNode` to the beginning of the List
    Node* pop_front() noexcept override; ///< Remove and return the first Node in the List

    void insert_after( Node* currentNode, Node* newNode ) ;  ///< Insert `newNode` after `currentNode`

    void dump() const noexcept override ;     ///< Output the contents of this container
    bool validate() const noexcept override ; ///< Check to see if the container is valid

}; // class SingleLinkedList

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_SINGLYLINKEDLIST_H
