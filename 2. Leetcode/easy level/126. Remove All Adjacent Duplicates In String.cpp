// link to question - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;        
        
        for(int i = 0; i < s.size(); i++){
                        
            if(ans.size() and ans.back() == s[i])
                ans.pop_back();
            else
                ans += s[i];
        }
        
        return ans;
    }
};