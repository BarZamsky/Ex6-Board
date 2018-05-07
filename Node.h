#include <iostream>
using namespace std;

class Node
{
    char val;

    public:
    Node();
    //Node(char val);
    void setNode(const char& val);
    const char getNode();
    Node& operator=(char val);
    bool operator==(char c) const;
    bool operator==(const Node& other) const;
    bool operator!=(char c) const;
    bool operator!=(const Node& other) const;
    operator char() const; //convet Node to char
    friend ostream& operator<< (ostream& os, Node& c);
};
inline ostream& operator<< (ostream& os, Node& n)
{
    os << n.getNode();
    return os;
}