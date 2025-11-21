#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

#define WHITE   "\x1b[38;5;231m"
#define BLACK   "\x1b[38;5;16m"
#define WHITEBG "\x1b[48;5;250m"
#define BLACKBG "\x1b[48;5;240m"
#define NORMBG  "\x1b[0m"
#define NORMFG  "\x1B[39m"

#define W_KING      "\u2654"
#define W_QUEEN     "\u2655"
#define W_ROOK      "\u2656"
#define W_BISHOP    "\u2657"
#define W_KNIGHT    "\u2658"
#define W_PAWN      "\u2659"

#define B_KING      "\u265A"
#define B_QUEEN     "\u265B"
#define B_ROOK      "\u265C"
#define B_BISHOP    "\u265D"
#define B_KNIGHT    "\u265E"
#define B_PAWN      "\u265F"

const int BOARD_RANK[8] = {8, 7, 6, 5, 4, 3, 2, 1}; 
const char BOARD_FILE[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

const std::string WHITE_RANK[8] = {W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN,
                                   W_KING, W_BISHOP, W_KNIGHT, W_ROOK};

const std::string BLACK_RANK[8] = {B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN,
                                   B_KING, B_BISHOP, B_KNIGHT, B_ROOK};

#endif