#include "Direction.hpp"
#include <string>
#include <vector>
using namespace std;

namespace ariel
{
    class Board
    {
    private:
        vector<vector<char>> board;
        unsigned int sumRows;
        unsigned int sumCols;
        unsigned int firstRow;
        unsigned int firstCol;
        void resizeBoard(unsigned int row, unsigned int col, unsigned int length, Direction direction);


    public:
        Board();
        void post(unsigned int row, unsigned int col, ariel::Direction direction, std::string content);
        std::string read(unsigned int row, unsigned int col, ariel::Direction direction, unsigned int length);
        void show();
    };
}