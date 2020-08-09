// link to question - https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

class Solution {
public:
    char findKthBit(int n, int k) {
        vector<bool> a = {false};
        
        for(int i = 2; i <= n; i++) {
            a.push_back(true);
            for(int j = a.size() - 2; j >= 0; j--) {
                a.push_back(!a[j]);
            }
        }
        
        if(a[k-1]) return '1';
        return '0';
    }
};