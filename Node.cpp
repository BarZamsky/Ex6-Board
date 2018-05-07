#include "Board.h"

Node::Node(){}

const char Node::getNode()
{
    return this->val;
}

bool Node::setNode(const char& val)
{
    this->val = val;
}


Node& Node::operator=(char val)
{
   if(val=='X' || val=='O'){
        this->val = val;
        return *this;
   }
    else
    {
        IllegalCharException ex;
        ex.setInput(val);
        throw ex;
    }
}

Node::operator char() const
{
    return this->val;
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