#include "piece.h"
#include "constants.h"


Piece::Piece(){}

/**
 * Constructor - used to initialize a new Piece object
 * 
 * @param color - unicode value for the fill color of this Piece
 * @param name  - the unicode value for this Piece's display symbol.
 */
Piece::Piece(std::string color, std::string name){
    this->color = color;
    this->name = name;
}


/**
 * Mutator - used to set the color of a piece
 * 
 * @param new_color - unicode value for the new fill color of this Piece
 */
void Piece::set_color(std::string new_color){
    color = new_color;
}

/**
 * Mutator - used to set the color of a piece
 * 
 * @param new_name - new unicode value for this Piece's display symbol
 */
void Piece::set_name(std::string new_name){
    name = new_name;
}

/**
 * Accessor - used to get the color of a piece
 */
std::string Piece::get_color(){
    return color;
}

/**
 * Accessor - used to get the name of a piece
 */
std::string Piece::get_name(){
    return name;
}