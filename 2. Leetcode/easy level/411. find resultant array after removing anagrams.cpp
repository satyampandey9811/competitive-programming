// link to question - https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& a) {
        int n = a.size();
        
        vector<string> ans;
        ans.push_back(a[0]);
        
        for (int i = 1; i < n; i++) {
            string b = ans.back();
            string c = a[i];
            sort(b.begin(), b.end());
            sort(c.begin(), c.end());
            if (b != c) ans.push_back(a[i]);
        }
        
        return ans;
    }
};