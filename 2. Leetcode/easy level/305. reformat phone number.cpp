// link to question - https://leetcode.com/problems/reformat-phone-number/

class Solution {
public:
    string reformatNumber(string a) {
        int n = a.size();
        string ans;
        for(int i = 0; i < n; i++) {
            if(a[i] >= '0' and a[i] <= '9') ans += a[i];
        }                
        
        string ret;
        n = ans.size();
        for(int i = 0; i < n; i++) {
            if(i + 3 < n - 1) {
                ret += ans.substr(i, 3);
                i += 2;
                ret += '-';
            }
            else if(i + 3 == n - 1) {
                ret += ans.substr(i, 2);
                ret += '-';
                i += 2;
                ret += ans.substr(i, 2);                
                break;
            }
            else {
                ret += ans.substr(i, n - i);
                break;
            }
        }
        
        return ret;
    }
};