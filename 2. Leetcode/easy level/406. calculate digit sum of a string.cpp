// link to question - https://leetcode.com/problems/calculate-digit-sum-of-a-string/

class Solution {
public:
    string sum (string s) {
        int ans = 0;
        for (auto &i :s) {
            ans += i - '0';
        }
        return to_string(ans);
    }
    
    string digitSum(string s, int k) {
        if (s.size() <= k) return s;
        string ans;
        
        int n = s.size();
        for (int i = 0; i < n; i += k) {
            if (i + k >= n) ans += sum(s.substr(i));
            else ans += sum(s.substr(i, k));
        }
        return digitSum(ans, k);
    }
};