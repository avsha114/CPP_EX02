#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

namespace ariel
{
    const unsigned int initSize = 5;

    Board::Board()
    {
        //Initialize with an arbitrary minimal size (5).
        sumRows = sumCols = initSize;

        //Set first location as maximum size. So later it will change to a lower number.
        firstRow = firstCol = UINT_MAX;

        //Initialize board.
        board = vector<vector<char>>(sumRows, vector<char>(sumCols, '_'));
    }

    void Board::post(unsigned int row, unsigned int col, Direction direction, string content)
    {
        unsigned int length = content.length();

        //If message destination cells are beyond board size it should start from zero to make sure it will fit.
        if (direction == Direction::Horizontal)
        {
            col = col > (UINT_MAX - length) ? 0 : col;
            row = (row == UINT_MAX) ? 0 : row;
        }
        else
        {
            row = row > (UINT_MAX - length) ? 0 : row;
            col = (col == UINT_MAX) ? 0 : col;
        }

        firstRow = min(firstRow, row);
        firstCol = min(firstCol, col);

        resizeBoard(row, col, length, direction);

        for (size_t i = 0; i < content.length(); i++)
        {
            board[row][col] = content.at(i); //Copy ad content to board.

            //Increase row or col accordingly.
            direction == Direction::Vertical ? row++ : col++;
        }
    }

    string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int length)
    {
        string output;

        for (size_t i = 0; i < length; i++)
        {
            if (col == UINT_MAX || row == UINT_MAX) //If we reached the bound of board.
            {
                while (i < length) //Finish string with '_'.
                {
                    output += '_';
                    i++;
                }
                return output;
            }

            //Add the next char or '_' if we finished the row/col size.
            if (row >= sumRows || col >= sumCols)
            {
                output += '_';
            }
            else
            {
                output += board[row][col];
            }

            //Increase row/col accordingly.
            direction == Direction::Vertical ? row++ : col++;
        }
        return output;
    }

    void Board::show()
    {
        cout << "/******Message Board******/";

        // Determine height and width to be 1 char away from the edged messages.
        unsigned int height = sumRows - firstRow + 2;
        unsigned int width = sumCols - firstCol + 1;
        unsigned int rowNumber = firstRow-1;

        for (unsigned int i = 0; i < height; i++, rowNumber++)
        {
            cout << endl << rowNumber << ": " << "_"
                  << read(firstRow-(unsigned int)1+i, firstCol, Direction::Horizontal, width);
        }
        cout << endl;
    }

    void Board::resizeBoard(unsigned int row, unsigned int col, unsigned int length, Direction direction)
    {
        //Determine the new number of rows and columns.
        if (direction == Direction::Vertical)
        {
            sumRows = max(sumRows, row + length);
            sumCols = max(sumCols, col + 1);
        }
        else
        {
            sumCols = max(sumCols, col + length);
            sumRows = max(sumRows, row + 1);
        }

        //Enlarge the board and fill with '_' .
        board.resize(sumRows);

        for (size_t i = 0; i < sumRows; i++)
        {
            board[i].resize(sumCols, '_');
        }
    }
}