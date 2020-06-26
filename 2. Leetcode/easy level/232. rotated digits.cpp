// link to question - https://leetcode.com/problems/rotated-digits/

class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            bool f = false;
            int j = i;
            while(j > 0) {
                int x = j % 10;
                if(x == 3 or x == 4 or x == 7) {
                    f = false;
                    break;
                }
                if(x == 2 or x == 5 or x == 6 or x == 9) 
                    f = true;
                j /= 10;
            }
            if(f) ans++;
        }
        return ans;
    }
};