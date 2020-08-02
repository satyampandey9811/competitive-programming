// link to question - https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    unordered_set<string> words;
    int n;
    vector<int> dp;
    string s;
    
    int check(int i) {
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];
        
        string word;
        for(int k = i; k < n; k++) {
            word += s[k];
            if(words.count(word)) {
                if(check(k + 1)) return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }    
    
    vector<string> backtrack(int i) {
        if(i == n) return {""};
                
        vector<string> ans;
        string prefix;
        
        for(int k = i; k < n; k++) {
            prefix += s[k];
            if(words.count(prefix) and dp[k+1]) {
                vector<string> temp = backtrack(k + 1);
                for(auto j: temp) {
                    if(j.size() > 0) ans.push_back(prefix + " " + j);
                    else ans.push_back(prefix);
                }                                
            }
        }
        
        return ans;
    }
    
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        n = str.size();
        dp.resize(n + 1, -1);
        s = str;        
        for(auto i: wordDict) words.insert(i);
        check(0);
        return backtrack(0);
    }
};