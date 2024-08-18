#include <iostream>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <chrono>


using namespace std;
unordered_map<long, int> map;





ofstream outputFile;

string getCurrentTimeString(){
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    tm* localTime = localtime(&currentTime);

    auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;

    stringstream ss;
    ss << "[" << put_time(localTime, "%Y-%m-%d %H:%M:%S")
       << ":" << setfill('0') << setw(3) << ms.count() << "]";

    return ss.str();
}



void Log(string info)
{
    string time = getCurrentTimeString();
    outputFile.open("History.txt");
    if(outputFile.is_open()){
        outputFile << "INFO:" << time <<":"<<info << endl;
        outputFile.close();
    }
    else{
        cout << "File Error" << endl;
    }
}







class statBundleNum
{
public:
    int BundleNum(int numofOP)
    {
        if ( numofOP < 3)
        {
            return 0;
        }
        else if (numofOP > 3 && numofOP <= 10)
        {
            return 1;
        }
        else if (numofOP > 10 && numofOP <= 15)
        {
            return 2;
        }
        else if (numofOP > 15)
        {
            return 3;
        }
        return -1;
    }
};

class Bundle_Interface
{
protected:
    float discount;

public:
    virtual float calculate_discount(float price) = 0;
};

class Bundle_0 : public Bundle_Interface
{
public:
    float calculate_discount(float price)
    {
        return price;
    }
};

class Bundle_1 : public Bundle_Interface
{
public:
    Bundle_1()
    {
        discount = 0.15;
    }

    float calculate_discount(float price)
    {
        return price - (price * discount);
    }
};

class Bundle_2 : public Bundle_Interface
{
public:
    Bundle_2()
    {
        discount = 100;
    }

    float calculate_discount(float price)
    {
        if (price > 200)
        {
            return price - discount;
        }
        else
            return price;
    }
};

class Bundle_3
{
private:
    Bundle_1 bun1;
    Bundle_2 bun2;
    float x;
    int num;

public:
    float calculate_discount(float price)
    {
        cout << "1) Discount by 15% then 100 L,E discount\n";
        cout << "2) 100 L,E discount then Discount by 15%\n";
        cout << "Which option would you like: ";

        while (!(cin >> num) || num > 2 || num < 1)
        {
            cout << "Error! Choose from prevoius numbers: ";
            cin.clear();
            cin.ignore(100, '\n');
        }

        if (num == 1)
        {
            x = bun1.calculate_discount(price);
            return bun2.calculate_discount(x);
        }
        else
        {
            x = bun2.calculate_discount(price);
            return bun1.calculate_discount(x);
        }
    }
};

void store(int id) {
    
    float Final_price;
    int bundleNum;
    if (map.find(id) != map.end()) {
        int numofOP = map[id]; // Access value in map
        float price;
        cout << "Please add price." << endl;
        cin >> price;
        statBundleNum S;
        numofOP++;
        map[id] = numofOP; 
        cout << "Number of Operations: " << numofOP << endl;
        bundleNum = S.BundleNum(numofOP);
        Bundle_0 bun0;
        Bundle_1 bun1;
        Bundle_2 bun2;
        Bundle_3 bun3;
        switch (bundleNum)
    {
    case 0:
        
        Final_price = bun0.calculate_discount(price);
        break;
    case 1:
        Final_price = bun1.calculate_discount(price);
        break;
    case 2:
        
        Final_price = bun2.calculate_discount(price);
        break;
    case 3:
        
        Final_price = bun3.calculate_discount(price);
        break;
    default:
        cout << "Invalid bundle number." << endl;
            return;
        }
       
        cout << "Final Price: " << Final_price << endl;
        Log("Enterfunction  \"Modify Customer\"");
        }}
int verifyId(int id)
{
    if (map.find(id) != map.end())
    {
        return 1; // ID found
    }
    return 0; // ID not found
}

void performOperation()
{
    int ID;
    cout << "Enter Customer ID: ";
    cin >> ID;
    if (verifyId(ID) != 1)
    {
        cout << "Invalid ID." << endl;
    }
    else
    {
        cout << "Valid ID." << endl;
        
        store(ID);
    }
}

void insertmap(unordered_map<long, int> &map, long ID, int numofOP) // Pass by reference
{
    map[ID] = numofOP;
}

void newCustomer()
{
    int id;
    cout << "Enter Customer ID: ";
    cin >> id;
    if (verifyId(id) == 1)
    {
        cout << "ID already exist." << endl;
    }
    else
    {
         Log("Enter function \"Add New Customer\"");
        insertmap(map, id, 0);
        cout << "ID added." << endl;
    }
}

void login()
{
    int n;
    cout << "\nHello to Topredo Store!\n"
         << "1.Add New Customer.\n"
         << "2.Perform Operation.\n"
         << "3.Exit." << endl;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "Add New Customer." << endl;
        newCustomer();
        break;
    case 2:
        cout << "Perform Operation." << endl;
        performOperation();
        break;
    case 3:
        cout << "Exit" << endl;
        for (auto x : map)
            cout << x.first << " " << x.second << endl;
        exit(0);
    default:
        cout << "Invalid Input." << endl;
        break;
    }
}
int main()
{
    
    
 




    int i = 100;
    while (i)
    {
        login();
        i--;
    }

    for (auto x : map)
        cout << x.first << " " << x.second << endl;
    return 0;
}