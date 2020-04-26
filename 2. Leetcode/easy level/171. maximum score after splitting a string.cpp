// link to question - https://leetcode.com/problems/maximum-score-after-splitting-a-string/

class Solution {
public:
    int maxScore(string s) {        
        int n = s.size() - 1, ans = 0, c, d;
        
        for(int i = 1; i <= n; i++){
            c = 0, d = 0;
            for(int j = 0; j < i; j++){
                if(s[j] == '0') c++;              
            }
            for(int k = i; k <= n; k++){
                if(s[k] == '1') d++;
            }
            ans = max(ans, c + d);
        }
        
        return ans;
    }
};