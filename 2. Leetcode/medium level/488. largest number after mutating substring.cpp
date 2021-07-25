// link to question - https://leetcode.com/problems/largest-number-after-mutating-substring/

class Solution {
public:
    string maximumNumber(string a, vector<int>& c) {
        int n = a.size(), x;
        bool f = true;
        
        for(int i = 0; i < n; i++) {
            x = a[i] - '0';
            if(x < c[x]) {
                a[i] = (char)(c[x] + '0');
                f = false;
            }
            else if(!f and x <= c[x]) {
                a[i] = (char)(c[x] + '0');
            }
            else if(!f) break;
        }
        
        return a;
    }
};