// link to question - https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/

class Solution {
public:
    bool isSumEqual(string a, string b, string c) {
        long long int d = 0, e = 0, f = 0;
        
        for(int i = 0; i < a.size(); i++) {
            d *= 10;
            d += a[i] - 'a';
        }
        
        for(int i = 0; i < b.size(); i++) {
            e *= 10;
            e += b[i] - 'a';
        }
        
        for(int i = 0; i < c.size(); i++) {
            f *= 10;
            f += c[i] - 'a';
        }
        
        return d + e == f;
    }
};