// link to question - https://leetcode.com/problems/water-and-jug-problem/

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x + y) return 0;
        if(z == x + y) return 1;
        if(x % 2 == 0 and y % 2 == 0){
            if(z % 2 == 0) return 1;
            else return 0;
        }
        if(x % 2 != 0 and y % 2 != 0) return 1;
        if(x > z and y > z and abs(x - y) > z) return 0;
        return 1;
    }
};

// one line solution
// return z == 0 || (z <= x + y && z % __gcd(x, y) == 0);