// link to question - https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.size();
        vector<int> a(26);
        
        for(int i = 0; i < n; i++) {
            a[s[i] - 'a'] = i; 
        }
        
        int last = 0, maxlast = 0;
        for(int i = 0; i < n; i++) {
            maxlast = max(maxlast, a[s[i] - 'a']);
            if(maxlast == i) {
                ans.push_back(maxlast - last + 1);
                last = i + 1;
            }
        }
        
        return ans;
    }
};