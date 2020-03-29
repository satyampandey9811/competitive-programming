// link to question - https://leetcode.com/problems/find-lucky-integer-in-an-array/

class Solution {
public:
    int findLucky(vector<int>& a) {
        int ans = -1;
        map<int, int> m;
        for(auto x: a)
            m[x]++;
        for(auto x: m){
            if(x.first == x.second)
                ans = x.first;
        }
        return ans;
    }
};