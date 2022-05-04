///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "List.h"

Node *List::get_next(const Node *currentNode) {
    if(currentNode == nullptr) {
        throw std::invalid_argument("Current node is pointed to null") ;
    }

    return currentNode->next ;
}

bool List::empty() const noexcept {
    if(head == nullptr) {
        return true ;
    }

    return false ;
}

unsigned int List::size() const noexcept {
    return count ;
}

bool List::isIn(Node *aNode) const {
    for(Node* traverse = head; traverse != nullptr ; traverse = traverse->next) {
        if(traverse == aNode) {
            return true ;
        }
    }

    return false ;
}

bool List::isSorted() const noexcept {
    if(head == nullptr) {
        return true ;
    }

    for(Node *traverse=head; traverse->next != nullptr; traverse=traverse->next) {
        if(traverse > traverse->next) {
            return false ;
        }
    }

    return true ;
}

Node *List::get_first() const noexcept {
    return head ;
}

void List::deleteAllNodes() noexcept {
    Node* traverse ;

    while(head != nullptr) {
        traverse = head ;
        head = head->next ;
        free(traverse) ;
    }
}
