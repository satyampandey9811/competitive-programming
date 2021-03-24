// link to question - https://leetcode.com/problems/advantage-shuffle/

class Solution {
public:
    vector<int> advantageCount(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans(n);
        multiset<int> ms(a.begin(), a.end());
        
        for(int i = 0; i < n; i++) {
            auto it = ms.upper_bound(b[i]);
            if(it == ms.end()) {
                it = ms.begin();
            }
            ans[i] = *it;
            ms.erase(it);
        }
        
        return ans;
    }
};