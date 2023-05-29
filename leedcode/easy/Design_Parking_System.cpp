class ParkingSystem {
public:
    int Big,Medium,Small;
    ParkingSystem(int big, int medium, int small) {
        Big=big;
        Medium=medium;
        Small=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(Big>0){
                Big=Big-1;
                return true;
            }
        }
          if(carType==2){
            if(Medium>0){
              Medium=  Medium-1;
                return true;
            }
        }
          if(carType==3){
            if(Small>0){
                Small=Small-1;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */