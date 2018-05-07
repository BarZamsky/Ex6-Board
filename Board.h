#pragma once
#include <iostream>
#include "Node.h"
#include <exception>
#include <list>
using namespace std;

class Board
{
    public:
    int rows;
    Node **game;
    Board(int r);
    Board(const Board& other);
    ~Board();
    bool operator==(const Board& other) const;
    Node& operator[](list<int> list);
    Board& operator=(const Board& b);
    Board& operator=(char c);
    friend ostream &operator<<(ostream &out, const Board &b);
};

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