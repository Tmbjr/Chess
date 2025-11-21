#include <iostream>
#include "tile.h"
#include "constants.h"
#include "piece.h"


Tile::Tile(){}

/**
 * Constructor - used to initialize a new Tile object.
 * 
 * @param occupied   - boolean flag denoting whether a piece sits on the Tile
 * @param color      - boolean flag denoting the color of the tile
 * @param fill_color - string containing the background fill color of the Tile
 * @param occupier   - Piece object that currently sits on this Tile
 */
Tile::Tile(bool occupied, bool color, std::string fill_color, Piece occupier){
    this->occupied = occupied;
    this->white = color;
    this->fill_color = fill_color;
    this->occupier = occupier;
}

/**
 * Accessor - used to determine whether this Tile is occupied
 */
bool Tile::get_occupied(){
    return occupied;
}

/**
 * Accessor - used to determine the color of this Tile
 */
bool Tile::get_color(){
    return white;
}

/**
 * Accessor - used to get the Piece occupying this Tile
 */
Piece Tile::get_occupier(){
    return occupier;
}

/**
 * Accessor - used to determine the fill color of this Tile
 */
std::string Tile::get_fill_color(){
    return fill_color;
}

/**
 * Mutator - used to alter the status of this Tile upon occupation or
 *           vacation. 
 * 
 * @param new_status - boolean flag for the state of occupation of this Tile
 */
void Tile::set_occupied(bool new_status){
    occupied = new_status;
}

/**
 * Mutator - used to set the color of this tile (white or !white)
 * 
 * @param new_white - boolean flag for the color of this Tile
 */
void Tile::set_white(bool new_white){
    white = new_white;
}

/**
 * Mutator - used to set the Peice occupying this Tile
 * 
 * @param new_occupier - Piece object now occupying this Tile 
 */
void Tile::set_occupier(Piece new_occupier){
    occupier = new_occupier;
}

/**
 * Mutator - used to set the fill color of this Tile
 * 
 * @param new_fill_color - string representing unicode value to use as the 
 *                         background fill color for this tile. 
 */
void Tile::set_fill_color(std::string new_fill_color){
    fill_color = new_fill_color;
}

/**
 * This method prints the contents of one layer (row) of the calling Tile.
 * 
 * @param row_index - integer index value for the layer of the calling Tile
 *                    to print. (0 - 2)
 */
void Tile::print_tile(int row_index){

    //ensure the occupier is up to date before printing
    if(row_index == 1){
        fill[1] = "  " + occupier.get_name() + "  ";
    }
    
    std::cout << fill_color << occupier.get_color() << fill[row_index];
    std::cout << NORMBG << NORMFG;
}