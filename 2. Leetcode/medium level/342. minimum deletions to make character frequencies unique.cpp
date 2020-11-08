// link to question - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> a(26);
        for(int i = 0; i < s.size(); i++) a[s[i] - 'a']++;
        sort(a.begin(), a.end(), greater<int>());
        
        int ans = 0, c = a[0];
        
        for(int i = 1; i < 26; i++) {
            if(a[i] == 0) break;
            if(a[i] >= c) {
                ans = ans + a[i] - c + 1;
                c--;
            }
            else c = a[i];
            
            if(c < 1) c = 1;
        }
        
        return ans;
    }
};