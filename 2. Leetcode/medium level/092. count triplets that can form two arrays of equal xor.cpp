// link to question - https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

class Solution {
public:
    int countTriplets(vector<int>& a) {
        int ans = 0, n = a.size(), x, y;
        for(int i = 0; i < n; i++) {
            x = a[i];
            for(int j = i + 1; j < n; j++) {
                y = 0;
                for(int k = j; k < n; k++) {
                    y ^= a[k];
                    if(x == y)
                        ans++;
                }
                x ^= a[j];
            }            
        }
        return ans;
    }
};