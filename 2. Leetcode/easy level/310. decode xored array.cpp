// link to question - https://leetcode.com/problems/decode-xored-array/

class Solution {
public:
    vector<int> decode(vector<int>& e, int first) {
        int n = e.size();
        vector<int> a(n + 1);
        a[0] = first;
        for(int i = 1; i <= n; i++) {
            a[i] = a[i-1] ^ e[i-1];
        }
        return a;
    }    
};