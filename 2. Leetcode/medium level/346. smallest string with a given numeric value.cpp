// link to question - https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string a;
        for(int i = 0; i < n; i++) a += 'a';
        k -= n;
        
        for(int i = n - 1; i >= 0 and k > 0; i--) {
            a[i] += min(25, k);
            k -= min(25, k);
        }
        
        return a;
    }
};