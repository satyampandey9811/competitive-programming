// link to question - https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {        
        int n = s.size(), ans = 0;
        unordered_map<char, int> m;
        
        for(int i = 0; i < n; i++) m[s[i]]++;
        
        bool odd = false;
        for(auto i: m) {
            if(i.second % 2 == 0) ans += i.second;
            else ans += i.second - 1;
            if(i.second & 1) odd = true;
        }
        if(odd) ans++;
        return ans;
    }
};