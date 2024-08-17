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
    int checkBundle();
    // Instead of just an integer, it should reference a Bundle object (polymorphic).
    // This allows the customer to switch between different bundles (e.g., Bundle1, Bundle2, Bundle3) dynamically.
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

int customers::checkBundle()
{
    switch (numofOP)
    {
    case 0 ... 2:
        return 0;
    case 3 ... 10:
        return 2;
    case 11 ... 15:
        int num;
        cout << "Would you like to change to Bundle 1?\n1. Yes\n2. No";
        while(!(cin>>num) || num > 2 || num < 1)
        {
            cout<<"Error! Choose from prevoius numbers: ";
            cin.clear();
            cin.ignore(100,'\n');
        }
        return num;
    default:
        return 3;
    }
}