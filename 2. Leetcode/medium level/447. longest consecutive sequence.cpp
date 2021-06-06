// link to question - https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        if(n == 0) return n;
        int ans = 1;
        unordered_set<int> s(a.begin(), a.end());
        
        for(auto &i : s) {
            if(!s.count(i-1)) {
                int y = i + 1;
                while(s.count(y)) {
                    ans = max(ans, y - i + 1);
                    y++;
                }
            }
        }
        
        return ans;
    }
};