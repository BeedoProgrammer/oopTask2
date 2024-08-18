#include <iostream>

using namespace std;

class Bundle_Interface{
    protected:
      float discount;  

    public:
      virtual float calculate_discount(float price) = 0;
      
};

class Bundle_0 : public Bundle_Interface{
    public:
      float calculate_discount(float price){
        return price;
      }
};

class Bundle_1 : public Bundle_Interface{
    public:
      Bundle_1(){
        discount = 0.15;
      }

      float calculate_discount(float price){
        return price - (price * discount);
      }
};

class Bundle_2 : public Bundle_Interface{
    public:
      Bundle_2(){
        discount = 100;
      }

      float calculate_discount(float price){
        if(price > 200){
          return price - discount;
        }
        else
          return price;
      }
};

class Bundle_3{
    private:
      Bundle_1 bun1;
      Bundle_2 bun2;
      float x;
      int num;

    public:
      float calculate_discount(float price){
      cout<<"1) Discount by 15% then 100 L,E discount\n";
      cout<<"2) 100 L,E discount then Discount by 15%\n";
      cout<<"Which option would you like: ";

      while(!(cin>>num) || num > 2 || num < 1){
          cout<<"Error! Choose from prevoius numbers: ";
          cin.clear();
          cin.ignore(100,'\n');
        }

        if(num == 1){
          x = bun1.calculate_discount(price);
          return  bun2.calculate_discount(x);
        }
        else{
          x = bun2.calculate_discount(price);
          return  bun1.calculate_discount(x);
        }
    }
};