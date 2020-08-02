// link to question - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, n = s.size(), j = 0;
        vector<int> a(3);
        
        for(int i = 0; i < n;) {
            a[s[i] - 'a']++;
            if(a[0] and a[1] and a[2]) {
                ans += n - i;
                a[s[j] - 'a']--;
                a[s[i] - 'a']--;
                j++;
            }
            else i++;
        }
        
        return ans;
    }
};