// link to question - https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 30; i++) {
            int x = a & (1 << i);
            int y = b & (1 << i);
            int z = c & (1 << i);
            if((x | y) != z) {
                ans++;                
                if(!z and x and y) ans++;
            }                    
        }
        return ans;
    }
};