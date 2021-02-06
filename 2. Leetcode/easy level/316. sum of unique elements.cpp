// link to question - https://leetcode.com/problems/sum-of-unique-elements/

class Solution {
public:
    int sumOfUnique(vector<int>& a) {
        int ans = 0, n = a.size();
        map<int, int> m;
        for(auto& i: a) m[i]++;
        for(auto& i: m) {
            if(i.second == 1) ans += i.first;
        }
        return ans;
    }
};