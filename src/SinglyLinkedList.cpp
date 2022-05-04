///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "SinglyLinkedList.h"
#include <iostream>
#include <cassert>
using namespace std ;

SinglyLinkedList::SinglyLinkedList() {
    assert( SinglyLinkedList::validate() ) ;
}

void SinglyLinkedList::push_front(Node *newNode) {
    if(!SinglyLinkedList::validate()) {
        throw std::domain_error("New node is not valid") ;
    }

    if(newNode == nullptr) {
        throw std::invalid_argument("New node cannot be null") ;
    }

    if( isIn(newNode) ) {
        throw std::logic_error("New node is already in container") ;
    }

    if( head != nullptr ) { // if linked list is not empty
        newNode->next = head;
        head = newNode;
    }

    else {	 // if linked list is empty
        newNode->next = nullptr;
        head = newNode;
    }

    count += 1 ;
}

Node *SinglyLinkedList::pop_front() noexcept {
    if(head == nullptr) {
        return nullptr ;
    }

    Node* tempNode = head ;

    if(head->next != nullptr) {
        head = head->next ;
    }

    else {
        head = nullptr ;
    }

    tempNode->next = nullptr ;

    assert( validate() ) ;

    return tempNode ;
}

void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {
    for(Node* traverse = head; traverse != nullptr ; traverse = traverse->next) {
        if(traverse == currentNode) {
            currentNode->next = newNode ;
        }
    }
}

void SinglyLinkedList::dump() const noexcept {
    cout << "SinglyLinkedList:  " << "head=["<< head << "]" << endl ;

    for(Node* traverse = head; traverse != nullptr ; traverse = traverse->next) {
        PRINT_HEADING_FOR_DUMP;
        traverse->dump();
    }
}

bool SinglyLinkedList::validate() const noexcept {

    int linkedListCount = 0 ;

    for(Node* traverse = head; traverse != nullptr ; traverse = traverse->next) {
        traverse->validate();
        linkedListCount += 1 ;
    }

    assert(size() == linkedListCount) ;

    return true;
}
