// link to question - https://leetcode.com/problems/number-of-pairs-with-concatenation-equal-to-target/

class Solution {
public:
    int numOfPairs(vector<string>& a, string t) {
        int ans = 0, n = a.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(a[i] + a[j] == t) ans++;
            }
        }
        return ans;
    }
};