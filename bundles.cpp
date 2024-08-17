class Bundle{
    protected:
      float discount;

    public:
      virtual float calculate_discount(float discount, float price) = 0;
};

class Bundle_0 : public Bundle{
    public:
      Bundle_0(){
        discount = 1;
      }

    float calculate_discount(float discount, float price){
        float discounted_price = price * discount;
        return discounted_price;
    }
};

class Bundle_1 : public Bundle{
    public:
      Bundle_1(){
        discount = 0.15;
      }

    float calculate_discount(float discount, float price){
        float discounted_price = price - (price * discount);
        return discounted_price;
    }
};