// link to question - https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        ios::sync_with_stdio(false), cin.tie(0);
        int n = a.size() + 1, x;
        a.push_back(0);
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {            
            x = a[i] % n;
            a[x] += n;
        }
        for(int i = 0; i < n; i++) {
            a[i] /= n;
            if(a[i] == 2) ans.push_back(i);
        }
        
        return ans;
    }
};