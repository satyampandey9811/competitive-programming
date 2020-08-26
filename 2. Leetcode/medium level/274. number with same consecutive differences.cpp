// link to question - https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
public:
    vector<int> ans;
    
    void go(int num, int len, int &k) {
        if(!len) {
            ans.push_back(num);
            return;
        }
        int x = num % 10;
        num *= 10;
        for(int i = 0; i < 10; i++) {
            if(abs(x - i) == k) {
                go(num + i, len - 1, k);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1) {
            for(int i = 0; i < 10; i++) ans.push_back(i);
            return ans;
        }
        
        for(int i = 1; i < 10; i++) {
            go(i, n - 1, k);
        }
        
        return ans;
    }
};