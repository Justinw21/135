#include <iostream>
#include "knights.h"

bool completed = false;

//prints 5x5 board from 2D array
void printBoard(int board[5][5])
{
    for(int row = 0; row < 5; row++)
    {
        for(int col = 0; col < 5; col++)
        {
            std::cout << board[row][col] << " ";
        }
        std::cout << "\n";
    }
}

//clears the last move in the board if it is not the correct move
void clearLastMove(int num, int board[5][5])
{
    for(int row = 0; row < 5; row++)
    {
        for(int col = 0; col < 5; col++)
        {
            if(board[row][col] >= num)
            {
                board[row][col] = 0;
            }
        }
    }
}

//Finds number in double array
bool findNum(int num, int board[5][5])
{
    for(int row = 0; row < 5; row++)
    {
        for(int col = 0; col < 5; col++)
        {
            if(board[row][col] == num)
            {
                return true;
            }
        }
    }
    return false;
}

//Checks if the board is full
bool finished(int board[5][5])
{    
    for(int i = 1; i <= 25; i++)
    {
        if(!(findNum(i, board)))
        {
            return false;
        }
    }
    return true;
}

void solve(int board[5][5], int row, int col, int moveNum)
{
    
    if(row < 0 || col < 0 || row >= 5 || col >= 5 || (board[row][col] <= moveNum && board[row][col] != 0))
    {
        return;
    }

    //Enters in the move from last recursive call
    board[row][col] = moveNum;


    //Checks if board is done
    if(finished(board))
    {
        std::cout << "\n";
        std::cout << "Answer: \n";
        printBoard(board);
        completed = true;
        return; 
    }

    //Recursive calls
    
    if(!completed){
        solve(board, row + 2, col + 1, moveNum + 1);
        if(!completed)
        {
            clearLastMove(moveNum + 1, board);
        }
        solve(board, row + 2, col - 1, moveNum + 1);
        if(!completed)
        {
            clearLastMove(moveNum + 1, board);
        }
        solve(board, row + 1, col + 2, moveNum + 1);
        if(!completed)
        {
            clearLastMove(moveNum + 1, board);
        }
        solve(board, row + 1, col - 2, moveNum + 1);
        if(!completed)
        {
            clearLastMove(moveNum + 1, board);
        }
        solve(board, row - 1, col + 2, moveNum + 1);
        if(!completed)
        {
            clearLastMove(moveNum + 1, board);
        }
        solve(board, row - 1, col - 2, moveNum + 1);
        if(!completed)
        {
            clearLastMove(moveNum + 1, board);
        }
        solve(board, row - 2, col + 1, moveNum + 1);
        if(!completed)
        {
            clearLastMove(moveNum + 1, board);
        }
        solve(board, row - 2, col - 1, moveNum + 1);
        if(!completed)
        {
            clearLastMove(moveNum + 1, board);
        }
    }
    
}


