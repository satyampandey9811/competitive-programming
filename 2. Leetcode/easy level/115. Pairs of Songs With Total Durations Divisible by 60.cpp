// link to question - https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& a) {
        vector<int> b(60);
        int n = a.size(), ans = 0;
        for(int i = 0; i < n; i++){
            b[a[i] % 60]++;
        }
        for(int i = 0; i <= 30; i++){
            if(b[i] == 0)
                continue;
            else if(i == 0 or i == 30)
                ans += (b[i] * (b[i] - 1)) / 2;            
            else {
                if(b[60 - i] != 0)
                    ans += b[i] * b[60 - i];
            }
        }
        return ans;
    }
};