#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <map>

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


const std::map<char, int> WHITE_FILE_CONV = {
                                            {'A', 0},
                                            {'B', 1},
                                            {'C', 2},
                                            {'D', 3},
                                            {'E', 4},
                                            {'F', 5},
                                            {'G', 6},
                                            {'H', 7}
                                         };

const std::map<char, int> BLACK_FILE_CONV = {
                                            {'A', 7},
                                            {'B', 6},
                                            {'C', 5},
                                            {'D', 4},
                                            {'E', 3},
                                            {'F', 2},
                                            {'G', 1},
                                            {'H', 0}
                                         };


const std::map<int, int> WHITE_RANK_CONV = {
                                            {1, 7},
                                            {2, 6},
                                            {3, 5},
                                            {4, 4},
                                            {5, 3},
                                            {6, 2},
                                            {7, 1},
                                            {8, 0}
                                         };

const std::map<int, int> BLACK_RANK_CONV = {
                                            {1, 0},
                                            {2, 1},
                                            {3, 2},
                                            {4, 3},
                                            {5, 4},
                                            {6, 5},
                                            {7, 6},
                                            {8, 7}
                                         };

#endif