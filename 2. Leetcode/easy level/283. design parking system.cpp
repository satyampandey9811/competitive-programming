// link to question - https://leetcode.com/problems/design-parking-system/

class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        b = big, m = medium, s = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(b) {
                b--;
                return 1;
            }
            return 0;
        }
        else if(carType == 2) {
            if(m) {
                m--;
                return 1;
            }
            return 0;
        }
        else {
            if(s) {
                s--;
                return 1;
            }
            return 0;
        }
    }    
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */