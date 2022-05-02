// link to question - https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/

class Solution {
public:
    string removeDigit(string a, char digit) {
        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == digit) {
                if (a[i] < a[i + 1]) {
                    return a.substr(0, i) + a.substr(i + 1);
                }
            }
        }
        string ans;
        
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == digit) {
                ans = a.substr(0, i) + a.substr(i + 1);
                break;
            }
        }
        
        return ans;
    }
};