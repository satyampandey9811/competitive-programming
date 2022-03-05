// link to question - https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/

class Solution {
public:
    int mostFrequent(vector<int>& a, int key) {
        int n = a.size();
        vector<int> b(1001);
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == key) b[a[i + 1]]++;
        }
        
        int ans;
        int c = 0;
        for (int i = 0; i < 1001; i++) {
            if (b[i] > c) {
                c = b[i];
                ans = i;
            }
        }
        
        return ans;
    }
};