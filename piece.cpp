#include "piece.h"
#include "constants.h"


Piece::Piece(){}
Piece::Piece(std::string color, std::string name){
    this->color = color;
    this->name = name;
}


void Piece::set_color(std::string new_color){
    color = new_color;
}

void Piece::set_name(std::string new_name){
    name = new_name;
}

std::string Piece::get_color(){
    return color;
}

std::string Piece::get_name(){
    return name;
}