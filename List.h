///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file List.h
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_LIST_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_LIST_H

#pragma once

#include "Node.h"

/// A generic list-based collection class.
///
class List {
protected:  ////////////////////// Protected Members ///////////////////////////
    Node* head = nullptr ;     ///< The head pointer for the collection
    unsigned int count = 0 ;   ///< Maintain a count of the number of Node objects in the collection

public:  /////////////////////////// Static Methods ////////////////////////////
    static Node* get_next( const Node* currentNode ) ;  ///< Get the next Node in the List

public:  /////////////////////////// Public Methods ////////////////////////////
    bool empty() const noexcept ;         ///< `true` if the List is empty
    unsigned int size() const noexcept ;  ///< Get the number of Node objects in the List

    bool isIn( Node* aNode ) const ; ///< `true` if `aNode` is in the List
    bool isSorted() const noexcept ; ///< `true` if the List is sorted

    Node* get_first() const noexcept ;  ///< Get the first Node in the List

    void deleteAllNodes() noexcept ;  ///< Delete all of the nodes in the List

public:  ////////////////////////// Abstract Methods ///////////////////////////
    virtual Node* pop_front() noexcept = 0 ;     ///< Remove and return the first Node in the List
    virtual void dump() const noexcept = 0;      ///< Output the contents of this container
    virtual bool validate() const noexcept = 0;  ///< Check to see if the container is valid
};

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_LIST_H
