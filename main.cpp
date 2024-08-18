#include <iostream>
#include <unordered_map>
using namespace std;

int verifyId(int id){
  return id==3355?1:0;
}
void performOperation(){
int ID;
cout<<"Enter Customer ID: ";
cin>>ID;
if(verifyId(ID)!=1){
    cout<<"Invalid ID."<<endl;
}
else{
    cout<<"Valid ID."<<endl;
    //Take op num from Hash map then ask user to mkae opreation 
}
}
void store(/*customer c*/){
    float price;
    cout<<"Please add price."<<endl;
    cin >> price;
    //cont
}
void insertmap(unordered_map<long, int>& map, long ID, int numofOP) // Pass by reference
{
    map[ID] = numofOP;
}

void newCustomer(){
    int id;
    cout<<"Enter Customer ID: ";
    cin>>id;
    if(verifyId(id)==1){
        cout<<"ID already exist."<<endl;
    }
    else{
      //  customers ch(id);
        
    unordered_map<long, int> map;
    insertmap(map, id, 0/* ch.opnumer*/);
    for (auto x : map) 
        cout << x.first << " " << x.second << endl;

        cout<<"ID added."<<endl;
    }
}


void login(){
    int n;
cout << "Hello to topredo Store!\n"
     << "1.Add New Customer.\n"
     <<"2.Perform Operation."<<endl;
cin>>n;
switch(n){
    case 1:
    cout<<"Add New Customer."<<endl;
    newCustomer();
    break;
    case 2:
    cout<<"Perform Operation."<<endl;
    performOperation();
    break;
    default:
    cout<<"Invalid Input."<<endl;
    break;

}}
int main(){
    login();
   
    return 0;
}