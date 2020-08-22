// link to question - https://leetcode.com/problems/thousand-separator/

class Solution {
public:
    string thousandSeparator(int n) {
        if(n == 0) return "0";
        int c = 0;
        string ans;
        while(n > 0) {
            c++;
            ans += to_string(n % 10);
            if(c == 3) ans += '.', c= 0;
            n /= 10;
        }
        if(ans.back() == '.') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};