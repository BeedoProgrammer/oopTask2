class Bundle_Interface{
    protected:
      float discount;

    public:
      virtual float calculate_discount(float discount, float price) = 0;
};

class Bundle_0 : public Bundle_Interface{
    public:
      float calculate_discount(float discount, float price){
        return price;
    }
};

class Bundle_1 : public Bundle_Interface{
    public:
      Bundle_1(){
        discount = 0.15;
      }

    float calculate_discount(float discount, float price){
        return price - (price * discount);
    }
};

class Bundle_2 : public Bundle_Interface{
    public:
      Bundle_2(){
        discount = 100;
      }

    float calculate_discount(float discount, float price){
        if(price > 200){
          return price - discount;
        }
        else
          return price;
    }
};