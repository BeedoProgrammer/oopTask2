class stateBundleNum {
public:
    int BundleNum(int numofOP)  {
        if (numofOP == 0 || numofOP < 3) {
            return 0;
        }
        else if (numofOP > 3 && numofOP <= 10) {
            return 1;
        }
        else if (numofOP > 10 && numofOP <= 15) {
            return 2;
        }
        else if (numofOP > 15) {
            return 3;
        }
      return -1;
    }
};