#include <iostream>
#include <cstdlib>
#include <cctype>

#include "constants.h"
#include "tile.h"
#include "piece.h"

void generateBoard(Tile[][8]);
void printBoard(Tile[][8], bool);
bool chooseColor();
void placePieces(Tile[][8], bool);
void clearScreen();

//bool playTurn(Tile[][8]);


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
    
    return 0; 
}




void generateBoard(Tile board[][8]){

    std::string fill_color = WHITEBG;

    //for every row
    for(int i = 0; i < 8; ++i){

        //for every column
        for(int j = 0; j < 8; ++j){
            //if we are on an even row
            if(i == 0 || i % 2 == 0){
                if(j == 0 || j % 2 == 0){
                    fill_color = WHITEBG;
                }
                else{
                    fill_color = BLACKBG;
                }
            }
            else{
                if(j == 0 || j % 2 == 0){
                    fill_color = BLACKBG;
                }
                else{
                    fill_color = WHITEBG;
                }
            }
            board[i][j].set_fill_color(fill_color);
        }
    }
    
    /*
    Tile board[64];
    std::string fill_color = WHITEBG;

    //for each row
    for(int i = 0; i < 8; ++i){

        //if this is an even row
        if(i == 0 || i % 2 == 0){
            //for each tile in this even row
            for(int j = 0; j < 8; ++j){
                //if this tile is an even tile
                if(j == 0 || j % 2 == 0){
                    fill_color = WHITEBG;
                }
                else{
                    fill_color = BLACKBG;
                }
                board[j + (i * 8)].set_fill_color(fill_color);

            }
        }
        else{ // if this is an odd row
            //for each tile in this odd row
            for(int j = 0; j < 8; ++j){
                //if this tile is an even tile
                if(j == 0 || j % 2 == 0){
                    fill_color = BLACKBG;
                }
                else{
                    fill_color = WHITEBG;
                }
                board[j + (i * 8)].set_fill_color(fill_color);

            }
        }


    }*/
}


void printBoard(Tile board[][8], bool white){ 

    std::cout << "\n\n";

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 3; ++j){

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

            for(int k = 0; k < 8; ++k){
                board[i][k].print_tile(j);
            }
            std::cout << std::endl;
        }
    }
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

void placePieces(Tile board[][8], bool white){
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


void clearScreen(){
    system("clear");
    system("clear");
}

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