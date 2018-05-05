#include <iostream>
#include "Board.h"
using namespace std;

Board::Board(const Board& other)
{
    rows=other.rows;
    game = new char*[rows];
    for (int i = 0; i < rows; i++) {
		game[i] = new char [rows];
	}
    for(int i = 0; i < rows; i++) {
	    for(int j = 0; j < rows; j++) {
			game[i][j] = other.game[i][j];
		}
	}
}

Board::Board(int n)
{
    rows=n;
    row=0,col=0;
    game = new char*[rows];
    for (int i = 0; i < rows; i++) {
		game[i] = new char [rows];
	}
    initBoard();
}

Board::~Board()
{
    for (int i = 0; i < rows; i++)
		delete[] game[i];
    delete [] game;
}

void Board::initBoard()
{
    for(int i = 0; i < rows; i++) {
		for(int j = 0; j < rows; j++) {
			game[i][j] = '.';
		}
	}
}

char &Board::operator[](list<int> list)
{
    row = list.front(), col=list.back();
    if (row>=rows || col>=rows || row<0 || col<0){
        IllegalCoordinateException ex;
        ex.setA(row); ex.setB(col);
        throw ex;
    }
    return game[row][col];
}


void Board::operator=(char c)
{   
    if(c=='.') {
        initBoard();
    }
    else if (c=='X' || c== 'O'){
        game[row][col] = c;
    }
    else{
        IllegalCharException ex;
        ex.setInput(c);
        throw ex;
    }
}

Board& Board::operator=(const Board& b)
{
    if (this==&b)
        return *this;
    if (b.rows!=this->rows) {
        for (int i = 0; i < rows; i++)
		    delete[] game[i];
        delete [] game;
        rows = b.rows;
        game = new char*[b.rows]; // init
        for (int i = 0; i < rows; i++) {
		game[i] = new char [rows];
	    }
    }
            
    for (uint i=0; i<rows; ++i){
        for(uint j=0;j<rows;j++){
            game[i][j]=b.game[i][j];
        }
    }
    return *this;
}
