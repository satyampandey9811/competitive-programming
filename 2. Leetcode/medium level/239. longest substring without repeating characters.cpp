// link to question - https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> a(256);
        int n = s.size(), ans = 0;
        
        for(int i = 0, j = 0; i < n; i++) {
            while(j < n and a[s[j]] < 1) {
                a[s[j]] = 1;
                j++;
            }
            ans = max(ans, j - i);
            a[s[i]]--;                        
        }
        
        return ans;
    }
};