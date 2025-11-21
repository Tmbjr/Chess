#include <iostream>
#include "tile.h"
#include "constants.h"
#include "piece.h"


Tile::Tile(){}

Tile::Tile(bool occupied, bool color, std::string fill_color, Piece occupier){
    this->occupied = occupied;
    this->white = color;
    this->fill_color = fill_color;
    this->occupier = occupier;
}

bool Tile::get_occupied(){
    return occupied;
}

bool Tile::get_color(){
    return white;
}
Piece Tile::get_occupier(){
    return occupier;
}

std::string Tile::get_fill_color(){
    return fill_color;
}

void Tile::set_occupied(bool new_status){
    occupied = new_status;
}

void Tile::set_white(bool new_white){
    white = new_white;
}

void Tile::set_occupier(Piece new_occupier){
    occupier = new_occupier;
}

void Tile::set_fill_color(std::string new_fill_color){
    fill_color = new_fill_color;
}

void Tile::print_tile(int row_index){

    fill[1] = "  " + occupier.get_name() + "  ";


    std::cout << fill_color << occupier.get_color() << fill[row_index];
    std::cout << NORMBG;
    std::cout << "\x1B[39m";
}