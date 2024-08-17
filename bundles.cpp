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
    private:
      float discounted_price;

    public:
      Bundle_1(){
        discount = 0.15;
      }

    float calculate_discount(float discount, float price){
        discounted_price = price - (price * discount);
        return discounted_price;
    }
};