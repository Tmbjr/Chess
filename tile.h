#ifndef TILE_H
#define TILE_H

#include <string> 
#include "piece.h"

class Tile{
    private:
        bool occupied = false;
        bool white = false; 
        Piece occupier;
        std::string fill_color = "\x1b[0m";
        std::string fill[3] = {"     ", "  " + occupier.get_name() + "  ", "     "};

    public:
        Tile(); 
        Tile(bool, bool, std::string, Piece);

        bool get_occupied();
        bool get_color();
        Piece get_occupier(); 
        std::string get_fill_color();

        void set_occupied(bool);
        void set_white(bool);
        void set_occupier(Piece);
        void set_fill_color(std::string);

        void print_tile(int);
};


#endif