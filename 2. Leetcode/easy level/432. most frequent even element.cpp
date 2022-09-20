// link to question - https://leetcode.com/problems/most-frequent-even-element/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> m;
        for (auto &i :nums) {
            m[i]++;
        }
        int v = 0, ans = -1;
        
        for (auto &i :m) {
            if (i.second > v and i.first % 2 == 0) {
                v = i.second;
                ans = i.first;
            }
        }
        
        return ans;
    }
};