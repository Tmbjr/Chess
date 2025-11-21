#include "movement.h"
#include "piece.h"
#include "constants.h"
#include "tile.h"


std::pair<int, int> convertCoords(std::pair<char, int> rankfile, bool white){
    if(rankfile.first >= 'A' && rankfile.first <= 'H' &&
       rankfile.second >= 1 && rankfile.second <= 8){
        
        int first = 0;
        int second = 0;

        //A1 -> 70 
        //last row, first col
        if(white){
            first = WHITE_RANK_CONV.at(rankfile.second);
            second = WHITE_FILE_CONV.at(rankfile.first);

        }
        else{
            
            first = BLACK_RANK_CONV.at(rankfile.second);
            second = BLACK_FILE_CONV.at(rankfile.first);
            
        }
        return {first, second};
    }
    
    return {-1, -1};// invalid coords; 
}


