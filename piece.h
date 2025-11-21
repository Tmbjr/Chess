#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include "constants.h"

class Piece{
    private:
        std::string color = WHITE;
        std::string name = " ";
        std::string position = "";
        std::vector<std::string> poss_moves; 


    public:
        Piece();
        Piece(std::string, std::string);

        void set_color(std::string);
        void set_name(std::string);

        std::string get_color();
        std::string get_name();



};


#endif