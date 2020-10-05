// link to question - https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/

class Solution {
public:
    vector<int> pathInZigZagTree(int v) {
        if(v == 1) return {1};
        vector<int> ans;
        
        int x = floor(log2(v));
        int pos, num;
        if(x & 1) {
            pos = pow(2, x + 1) - v - 1 + pow(2, x);
        } 
        else pos = v;
        
        while(pos > 0) {
            x = floor(log2(pos));
            if(x & 1) 
                num = pow(2, x + 1) - 1 - pos + pow(2, x);
            else 
                num = pos;
            ans.push_back(num);
            pos /= 2;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};