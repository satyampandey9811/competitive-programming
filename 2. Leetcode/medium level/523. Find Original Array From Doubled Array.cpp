// link to question - https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int n = a.size();
        if(n < 2) return {};
        vector<int> ans;
        sort(a.begin(), a.end());
        map<int, int> m;
        for(int i = 0; i < n; i++) m[a[i]]++;
        
        for(int i = 0; i < n; i++) {
            if(m[a[i]] < 1) continue;
            m[a[i]]--;
            if(m[2 * a[i]] < 1) return {};
            ans.push_back(a[i]);
            m[2 * a[i]]--;
        }
        
        return ans;
    }
};