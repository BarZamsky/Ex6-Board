#include "Board.h"

Board::Board(int r)
{
    rows=r;
    game = new Node*[rows];
    for (int i = 0; i < rows; i++) {
		game[i] = new Node [rows];
	}
    initBoard();
}

void Board::initBoard()
{
    for(int i = 0; i < rows; i++) {
		for(int j = 0; j < rows; j++) {
			game[i][j].setNode('.');
		}
	}
}

Board::Board(const Board& other)
{
    rows=other.rows;
    game = new Node*[rows];
    for (int i = 0; i < rows; i++) {
		game[i] = new Node [rows];
        for(int j=0;j<rows;j++){
            game[i][j]=other.game[i][j];
        }
	}
}

Board::~Board()
{
    for(int i=0;i<rows;i++){
        delete[] game[i];
    }
    delete[] game;
}

Node& Board::operator[](list<int> list)
{
    int a = list.front(), b=list.back();
    if(a<0 || a>=rows || b<0 || b>=rows)
    {
        IllegalCoordinateException ex;
        ex.setA(a); ex.setB(b);
        throw ex;
    }   
    else
        return game[a][b];
}

Board& Board::operator=(const Board &b)
{
     if (this==&b)
        return *this;
    if (b.rows!=this->rows) {
        for (int i = 0; i < rows; i++)
		    delete[] game[i];
        delete [] game;
        rows = b.rows;
        game = new Node*[b.rows]; // init
        for (int i = 0; i < rows; i++) {
		game[i] = new Node [rows];
	    }
    }
            
    for (uint i=0; i<rows; ++i){
        for(uint j=0;j<rows;j++){
            game[i][j]=b.game[i][j];
        }
    }
    return *this;
}

void Board::operator=(char c)
{
    if (c=='.') 
        initBoard();
    else
    {
       IllegalCharException ex;
        ex.setInput(c);
        throw ex; 
    }
}

bool Board::operator==(const Board &other) const
{
    if (rows != other.rows)
        return false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (game[i][j] != other.game[i][j])
                return false;
        }
    }
    return true;
}