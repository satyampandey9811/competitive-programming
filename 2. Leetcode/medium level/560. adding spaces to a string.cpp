// link to question - https://leetcode.com/problems/adding-spaces-to-a-string/

class Solution {
public:
    string addSpaces(string s, vector<int>& a) {
        
        int sp;
        int i = 0, j = 0;
        int m = s.size(), n = a.size();
        
        string ans;
        
        while (j < n) {
            sp = a[j];
            while (i < m and i < sp) ans += s[i++];
            if (i == sp) ans += ' ';
            j++;
        }
        
        while (i < m) {
            ans += s[i++];
        }
        
        return ans;
    }
};