// link to question - https://leetcode.com/problems/final-value-of-variable-after-performing-operations/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& a) {
        int ans = 0;
        for(int i = 0; i < (int)a.size(); i++) {
            if(a[i] == "++X" or a[i] == "X++") ans++;
            else ans--;
        }
        return ans;
    }
};