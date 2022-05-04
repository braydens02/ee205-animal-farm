///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Node.cpp
/// @version 1.0
///
/// @author Brayden Suzuki <braydens@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Node.h"

using namespace std ;

bool Node::compareByAddress(const Node *node1, const Node *node2) {
    if( node2 > node1 ) {
        return false ;
    }
    return true ;
}

void Node::dump() const {
    FORMAT_LINE_FOR_DUMP("Node", "this") << this << endl ;
    FORMAT_LINE_FOR_DUMP("Node", "next") << next << endl ;
}

bool Node::validate() const noexcept {
    if( next == nullptr ) /* nullptr is valid for next */ {
        return true ;
    }

    if( next == next->next ) /* next pointer points to itself */ {
        return false ;
    }

    return true ;
}

bool Node::operator>(const Node& rightSide) {
    return Node::compareByAddress(this, &rightSide) ;
}
