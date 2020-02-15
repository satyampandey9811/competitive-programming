// link to question - https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& a, int k) {
        if(k < 0) return 0;
        int ans = 0;
        unordered_map<int, int> um;
        for(int i = 0; i < a.size(); i++) um[a[i]]++;
        for(auto x: um){
            if(k == 0 and x.second > 1)        
                ans += 1;       
            else if(k != 0 and um.find(x.first + k) != um.end())
                ans++;            
        }
        return ans;
    }
};