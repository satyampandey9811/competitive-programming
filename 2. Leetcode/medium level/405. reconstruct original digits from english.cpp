// link to question - https://leetcode.com/problems/reconstruct-original-digits-from-english/

class Solution {
public:
    string originalDigits(string s) {
        int n = s.size();
        vector<int> a(26), b(10);
        string ans;
        
        for(int i = 0; i < n; i++) {
            a[s[i] - 'a']++;
        }
        
        b[0] = a['z' - 'a'];
        a['o' - 'a'] -= b[0];
        
        b[6] = a['x' - 'a'];
        a['s' - 'a'] -= b[6];
        
        b[2] = a['w' - 'a'];
        a['o' - 'a'] -= b[2];
        
        b[8] = a['g' - 'a'];
        a['g' - 'a'] -= b[8];
        a['h' - 'a'] -= b[8];
        
        b[3] = a['h' - 'a'];
        
        b[4] = a['u' - 'a'];
        a['f' - 'a'] -= b[4];
        a['o' - 'a'] -= b[4];
        
        b[1] = a['o' - 'a'];
        a['n' - 'a'] -= b[1];
        
        b[5] = a['f' - 'a'];
        
        b[7] = a['s' - 'a'];
        a['n' - 'a'] -= b[7];
        
        b[9] = a['n' - 'a'] / 2;
        
        for(int i = 0; i < 10; i++) {
            for(int j = 1; j <= b[i]; j++) ans += to_string(i);
        }
        
        return ans;
    }
};