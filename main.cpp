#include <iostream>
#include <cstdlib>
#include <cctype>

#include "constants.h"
#include "tile.h"
#include "piece.h"
#include "movement.h"

void generateBoard(Tile[][8]);
void printBoard(Tile[][8], bool);
bool chooseColor();
void placePieces(Tile[][8], bool);
void clearScreen();

int main (){
    //initialize and fill board with tiles
    Tile board[8][8];
    generateBoard(board);

    //get player's choice of color
    bool white = chooseColor(); 
    placePieces(board, white);
    
    //draw board
    clearScreen();
    printBoard(board, white);

    std::cout << "ENTER a piece to move by rank/file i.e. 'A1'\n:";
    std::string selection = "";
    std::cin >> selection;


    std::pair<int, int> converted = convertCoords({selection[0], selection[1] - '0'}, white);

    if(converted.first > 0){
        std::cout << "converted coords " << selection << " to " << converted.first << converted.second;
    }

    
    return 0; 
}

/**
 * This function is used to generate a new blank 8x8 board of Tile
 * objects.
 * 
 * @param board[][8] - an 8x8 2-dimensional array of tile objects used
 *                     to represent a chess board.
 */
void generateBoard(Tile board[][8]){

    std::string fill_color = WHITEBG;

    //for every row
    for(int i = 0; i < 8; ++i){
        //for every column
        for(int j = 0; j < 8; ++j){
            //if row index is even, even cols white
            if(i == 0 || i % 2 == 0){
                if(j == 0 || j % 2 == 0){
                    fill_color = WHITEBG;
                }
                else{
                    fill_color = BLACKBG;
                }
            }
            //if row index is odd, even cols black
            else{
                if(j == 0 || j % 2 == 0){
                    fill_color = BLACKBG;
                }
                else{
                    fill_color = WHITEBG;
                }
            }
            //set the fill color
            board[i][j].set_fill_color(fill_color);

            //if this Tile is white, set its flag
            if(fill_color == WHITEBG){
                board[i][j].set_white(true);
            }
        }
    }
}

/**
 * This function prints the current contents of the chess board to stdout
 * 
 * @param board[][8] - an 8x8 2-dimensional array of tile objects used
 *                     to represent a chess board.
 * 
 * @param white - boolean flag for the color of the player's pieces used to
 *                print rank and file labels in the correct orientation.
 */
void printBoard(Tile board[][8], bool white){ 

    std::cout << "\n\n";

    //for every row of tiles
    for(int i = 0; i < 8; ++i){
        //for each layer of each tile
        for(int j = 0; j < 3; ++j){

            //if this is the middle layer of the tile, print a rank label
            if(j == 1){
                if(white){
                    std::cout << " " << BOARD_RANK[i] << " ";
                }
                else{
                    std::cout << " " << BOARD_RANK[7 - i] << " ";
                }
            }
            else{
                std::cout << "   ";
            }

            //for each column (k) of tiles in row (i), print layer of index (j)
            for(int k = 0; k < 8; ++k){
                board[i][k].print_tile(j);
            }
            std::cout << std::endl;
        }
    }
    //print file labels 
    std::cout << "     "; 
    if(white){
        for(char c : BOARD_FILE){
            std::cout << c << "    ";
        }
    }
    else{
        for(int i = 7; i >= 0; --i){
            std::cout << BOARD_FILE[i] << "    ";
        }
    }
    std::cout << std::endl;

}

/**
 * This function is used to place chess pieces in their starting positions on
 * the newly created board. 
 * 
 * @param board[][8] - an 8x8 2-dimensional array of tile objects used
 *                     to represent a chess board.
 * @param white - boolean flag for the color of the player's pieces used to
 *                place pieces of each color on their respective sides.
 */
void placePieces(Tile board[][8], bool white){

    //handle placement of pieces if the player has chosen to play as white.
    if(white){
        for(int i = 0; i < 2; ++i){
            if(i == 0){
                for(int j = 0; j < 8; ++j){
                    Piece new_piece = Piece(BLACK, BLACK_RANK[j]);
                    board[i][j].set_occupier(new_piece);
                }
            }
            else{
                for(int j = 0; j < 8; ++j){
                    Piece new_piece = Piece(BLACK, B_PAWN);
                    board[i][j].set_occupier(new_piece);
                }
            }
        }
        for(int i = 6; i < 8; ++i){
            if(i == 6){
                for(int j = 0; j < 8; ++j){
                    Piece new_piece = Piece(WHITE, W_PAWN);
                    board[i][j].set_occupier(new_piece);
                }
            }
            else{
                for(int j = 0; j < 8; ++j){
                    Piece new_piece = Piece(WHITE, WHITE_RANK[j]);
                    board[i][j].set_occupier(new_piece);
                }
            }
        }
    }
    //handle placement of pieces if the player has chosen to play as black. 
    else{
        for(int i = 0; i < 2; ++i){
            if(i == 0){
                for(int j = 0; j < 8; ++j){
                    Piece new_piece = Piece(WHITE, WHITE_RANK[j]);
                    board[i][j].set_occupier(new_piece);
                }
            }
            else{
                for(int j = 0; j < 8; ++j){
                    Piece new_piece = Piece(WHITE, W_PAWN);
                    board[i][j].set_occupier(new_piece);
                }
            }
        }
        for(int i = 6; i < 8; ++i){
            if(i == 6){
                for(int j = 0; j < 8; ++j){
                    Piece new_piece = Piece(BLACK, B_PAWN);
                    board[i][j].set_occupier(new_piece);
                }
            }
            else{
                for(int j = 0; j < 8; ++j){
                    Piece new_piece = Piece(BLACK, BLACK_RANK[j]);
                    board[i][j].set_occupier(new_piece);
                }
            }
        }
    }
}

/**
 * This function clears the terminal to simulate a refresh of the board.
 */
void clearScreen(){
    system("clear");
    system("clear");
}

/**
 * This function handles the player's choice of piece color to play as.
 * 
 * @return white - a boolean flag for the color of the player's pieces.
 */
bool chooseColor(){
    //prompt user to choose color
    bool white = true; 
    char decision = ' ';

    while(decision != 'W' && decision != 'B' && decision != 'Q'){
        clearScreen();
        std::cout << R"(   _____ _    _ ______  _____ _____ 
  / ____| |  | |  ____|/ ____/ ____|
 | |    | |__| | |__  | (___| (___  
 | |    |  __  |  __|  \___ \\___ \ 
 | |____| |  | | |____ ____) |___) |
  \_____|_|  |_|______|_____/_____/ 

            [ C H E S S ]
)" << std::endl;
        std::cout << "\nEnter W to play as WHITE\n"
                    << "Enter B to play as BLACK\n"
                    << "Enter Q to quit\n:";
        std::cin >> decision;
        decision = std::toupper(decision);
    }
    
    if(decision == toupper('q')){
        clearScreen();
        exit(1);
    }
    else if(decision != toupper('w')){
        white = false;
    }

    return white; 
}