// link to question - https://leetcode.com/problems/word-break/

class Solution {
public:
    unordered_set<string> words;
    int n;
    vector<int> dp;
    
    bool check(int i, string &s) {        
        if(i == n) return 1;        
        if(dp[i] != -1) return dp[i];
        
        string word;
        
        for(int k = i; k < n; k++) {
            word += s[k];
            if(words.count(word)) {
                if(check(k + 1, s))
                    return dp[i] = 1;
            }
        }
        
        return dp[i] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto i: wordDict) words.insert(i);
        n = s.size();
        dp.resize(n + 1, -1);
        return check(0, s);
    }
};