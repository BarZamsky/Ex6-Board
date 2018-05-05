#pragma once
#include <iostream>
#include <exception>
#include <list>

using namespace std;

class Board
{
    uint rows;
    char** game;
    int row,col;

    public:
    Board(int n);
    Board(const Board& other); // copy constructor
    ~Board();
    void initBoard();

    char &operator[](list<int> list);
    Board& operator=(const Board& b);
    void operator=(char c);
    friend ostream& operator<<(ostream& os, const Board& b);
};

inline ostream& operator<<(ostream& os, const Board& b)
    {
    for(int i=0; i<b.rows; i++){
        for(int j=0; j<b.rows; j++){
            os<<b.game[i][j];
            }
        os<<endl;
        }
    return os;
    }

class IllegalCoordinateException : public exception
{
    int a,b;
    public: 
        void setA(int row){
            this->a=row;
            }
        void setB(int col){
            this->b=col;
            }
        string theCoordinate ()const
        {
            return to_string(a)+","+to_string(b);
        }
};

class IllegalCharException : public exception
{
    char input;
    public:
        char theChar()const
        {
            return input;
        }
        void setInput(int c){input=c;}
};

