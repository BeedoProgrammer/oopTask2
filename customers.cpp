#include<iostream>
using namespace std;

class customers
{
private:
    long id;
    int numofOP; 
public:
    customers(long id);
    void countOP();
};

customers::customers(long id)
{
    this->id = id;
    this->numofOP = 0;
}

void customers::countOP()
{
   this->numofOP++; 
}