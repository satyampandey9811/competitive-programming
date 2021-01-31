// link to question - https://leetcode.com/problems/maximum-number-of-balls-in-a-box/

class Solution {
public:
    int countBalls(int l, int h) {
        map<int, int> m;
        for(int i = l; i <= h; i++) {
            int val = i, sum = 0;
            while(val > 0) {
                sum += val % 10;
                val /= 10;
            }
            m[sum]++;
        }
        
        int ans = 0;
        for(auto& i: m) {
            ans = max(ans, i.second);
        }
        
        return ans;
    }
};