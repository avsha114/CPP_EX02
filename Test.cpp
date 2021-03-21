/**
 * Test file written by Avshalom Avraham
 */

#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace ariel;
using namespace std;

Board board;

TEST_CASE("Valid input tests")
{
    Board testBoard;

    //Check different input/outputs with different lengths for exceptions.
    CHECK_NOTHROW(testBoard.post(3, 0, Direction::Vertical, "Test!"));
    CHECK_NOTHROW(testBoard.post(1000, 0, Direction::Vertical, "Test!"));
    CHECK_NOTHROW(testBoard.post(0, 3, Direction::Horizontal, "Test!"));
    CHECK_NOTHROW(testBoard.post(0, 10000, Direction::Horizontal, "Test!"));
    CHECK_NOTHROW(testBoard.read(3, 0, Direction::Vertical, 5));
    CHECK_NOTHROW(testBoard.read(1000, 0, Direction::Vertical, 2));
    CHECK_NOTHROW(testBoard.read(0, 3, Direction::Horizontal, 0));
    CHECK_NOTHROW(testBoard.read(0, 1000, Direction::Horizontal, 0));

    //Check no exceptions with and without an ad.
    CHECK_NOTHROW(testBoard.read(30, 24, Direction::Horizontal, 5));
    CHECK_NOTHROW(testBoard.post(30, 24, Direction::Horizontal, "Test!"));
    CHECK_NOTHROW(testBoard.read(30, 24, Direction::Horizontal, 5));

    //Check for maximum index.
    CHECK_NOTHROW(testBoard.post(UINT_MAX, 0, Direction::Horizontal, "Test!"));
    CHECK_NOTHROW(testBoard.read(0, UINT_MAX, Direction::Horizontal, 5));
}

TEST_CASE("Post and Read tests on blank board")
{
    board.post(0, 0, Direction::Horizontal, "test1");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "test1");

    board.post(0, 5, Direction::Horizontal, "test2");
    CHECK(board.read(0, 5, Direction::Horizontal, 5) == "test2");

    board.post(1, 0, Direction::Vertical, "test3");
    CHECK(board.read(1, 0, Direction::Vertical, 5) == "test3");

    board.post(1, 1, Direction::Horizontal, "test4");
    CHECK(board.read(1, 1, Direction::Horizontal, 5) == "test4");

    board.post(1, 6, Direction::Vertical, "test5");
    CHECK(board.read(1, 6, Direction::Vertical, 5) == "test5");

    board.post(20, 30, Direction::Horizontal, "test6");
    CHECK(board.read(20, 30, Direction::Horizontal, 5) == "test6");

    board.post(21, 30, Direction::Vertical, "test7");
    CHECK(board.read(21, 30, Direction::Vertical, 5) == "test7");
}

TEST_CASE("Post and Read tests on used board")
{
    board.post(19, 30, Direction::Vertical, "test8");
    CHECK(board.read(19, 30, Direction::Vertical, 5) == "test8");
    CHECK(board.read(20, 30, Direction::Horizontal, 5) == "eest6");

    board.post(0, 0, Direction::Horizontal, "test9");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "test9"); 

    board.post(0, 5, Direction::Horizontal, "test10");
    CHECK(board.read(0, 5, Direction::Horizontal, 6) == "test10"); 

    board.post(1, 0, Direction::Vertical, "test11");
    CHECK(board.read(1, 0, Direction::Vertical, 6) == "test11"); 

    board.post(1, 1, Direction::Horizontal, "test12");
    CHECK(board.read(1, 1, Direction::Horizontal, 6) == "test12"); 

    board.post(1, 6, Direction::Vertical, "test13");
    CHECK(board.read(1, 6, Direction::Vertical, 6) == "test13");
}