// link to question - https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        
        vector<int> ans(num + 1); 
        if(num) 
            ans[1] = 1;
        int j = 0;
        
        for(int i = 2; i <= num; i++){
            if((i & (i - 1)) == 0)
                j = 0;                            
            ans[i] = ans[j++] + 1;
        }
        
        return ans;
    }
};