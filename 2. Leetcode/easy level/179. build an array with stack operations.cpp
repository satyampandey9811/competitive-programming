// link to question - https://leetcode.com/problems/build-an-array-with-stack-operations/

class Solution {
public:
    vector<string> buildArray(vector<int>& a, int n) {
        vector<string> ans;
        unordered_set<int> s(a.begin(), a.end());
        
        for(int i = 1; i <= a.back(); i++) {
            ans.push_back("Push");
            if(s.find(i) == s.end()) {
                ans.push_back("Pop");
            }            
        }
        return ans;
    }
};