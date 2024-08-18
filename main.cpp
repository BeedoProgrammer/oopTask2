#include <iostream>

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
void newCustomer(){
    int id;
    cout<<"Enter Customer ID: ";
    cin>>id;
    if(verifyId(id)==1){
        cout<<"ID already exist."<<endl;
    }
    else{
        //Add ID to Hash map
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