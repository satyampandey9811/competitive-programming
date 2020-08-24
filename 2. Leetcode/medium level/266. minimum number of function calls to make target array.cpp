// link to question - https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/

class Solution {
public:
    int minOperations(vector<int>& a) {        
        int ans = 0;        
        
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < 30; j++) {
                if(a[i] & (1 << j)) ans++;
            }
        }
        
        ans += log2(*max_element(a.begin(), a.end()));
        
        return ans;
    }
};