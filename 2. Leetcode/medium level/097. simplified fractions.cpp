// link to question - https://leetcode.com/problems/simplified-fractions/

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if(n == 1) return {};
        vector<string> ans;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                int gcd = __gcd(i, j);                
                if(gcd == 1) {
                    string a = to_string(j);
                    string b = to_string(i);
                    a += '/';
                    a += b;
                    ans.push_back(a);
                }                
            }
        }
        return ans;
    }
};