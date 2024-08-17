class Bundle{
    protected:
      float discount;

    public:
      virtual float calculate_discount(float discount, float price) = 0;
};