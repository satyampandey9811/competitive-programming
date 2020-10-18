// link to question - https://leetcode.com/problems/largest-substring-between-two-equal-characters/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> a(26, -1);
        int ans = -1;
        
        for(int i = 0; i < s.size(); i++) {
            if(a[s[i] - 'a'] == -1) a[s[i] - 'a'] = i;
            else ans = max(ans, i - a[s[i] - 'a'] - 1);                
        }
        
        return ans;
    }
};