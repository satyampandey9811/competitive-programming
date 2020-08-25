// link to question - https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int x) {
        int ans = 0, n = grumpy.size();
        for(int i = 0; i < n; i++) {
            if(!grumpy[i]) ans += customers[i];
        }
        
        int c = 0, sum = 0, res = 0;
        for(int i = 0; i < n; i++) {
            c++;
            if(grumpy[i]) sum += customers[i];
            if(c == x) {
                res = max(res, sum);
                if(grumpy[i-x+1]) sum -= customers[i-x+1];
                c--;
            }
        }
        
        return ans + res;
    }
};