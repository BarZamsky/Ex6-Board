#include "Board.h"

Node::Node(){}

Node::Node(char c)
{
    if(c=='X' || c== 'O' || c=='.')
        this->val = c;
    else{
        IllegalCharException ex;
        ex.setInput(val);
        throw ex;
    }
}
Node::Node(const Node& n)
{
    this->val = n.getNode();
}
char Node::getNode() const
{
    return this->val;
}

Node& Node::operator=(char val)
{
   if(val=='X' || val=='O' || val=='.'){
        this->val = val;
        return *this;
   }
    else
    {
        IllegalCharException ex;
        ex.setInput(val);
        throw ex;
    }
    return *this;
}

bool Node::operator==(char c) const
{
    return val == c;
}

bool Node::operator==(const Node& other) const
{
    return val == other.val;
}

bool Node::operator!=(char c) const {
    return val != c;
}

bool Node::operator!=(const Node& other) const {
    return val != other.val;
}