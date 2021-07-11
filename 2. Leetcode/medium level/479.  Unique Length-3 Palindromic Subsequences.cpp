// link to question - https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.size(), res = 0;
        
        vector<vector<int>> a(26, vector<int>(n + 1));
        
        vector<int> first(26, -1), last(26, -1);
        
        for(int i = 0; i < n; i++) {
            a[s[i] - 'a'][i+1]++;
            
            if(first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            
            last[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < 26; i++) {
            for(int j = 1; j <= n; j++) {
                a[i][j] += a[i][j-1];
            }
        }
        
        for(int i = 0; i < 26; i++) {
            int st = first[i], en = last[i];
            if(en - st < 2) continue;
            
            for(int j = 0; j < 26; j++) {
                if(a[j][en] - a[j][st+1] > 0) 
                    res++;    
            }
        }
        
        return res;
    }
};