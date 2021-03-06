// link to question - https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        
        for(int i = 0; i < n; i++) {
            vector<int> a(26);
            for(int j = i; j < n; j++) {
                a[s[j] - 'a']++;
                
                int low = 501, high = 0;
                for(int k = 0; k < 26; k++) {
                    if(a[k]) {
                        low = min(low, a[k]);
                        high = max(high, a[k]);
                    }
                }

                ans += high - low;
            }
        }
        
        return ans;
    }
};