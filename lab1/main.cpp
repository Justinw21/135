#include <iostream>
#include "knights.h"

int main()
{
    int board[5][5] = {{0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0}};

    printBoard(board);
    
    solve(board, 0, 0, 1); //Starts at the top left of the 2D array
    return 0;
}