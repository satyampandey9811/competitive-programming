// link to question - https://leetcode.com/problems/orderly-queue/

class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans = s;
        if(k > 1) sort(ans.begin(), ans.end());
        else {
            int n = s.size();
            for(int i = 1; i < n; i++) {
                ans = min(ans, s.substr(i) + s.substr(0, i));
            }
        }
        return ans;
    }
};