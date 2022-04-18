// link to question - https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
public:
    int minimumRounds(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> m;
        for (auto &i :a) m[i]++;
        int ans = 0;
        
        for (auto &i :m) {
            if (i.second == 1) return -1;
            ans += ceil(i.second * 1.0 / 3);
        }
        
        return ans;
    }
};