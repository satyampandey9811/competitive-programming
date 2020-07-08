// link to question - https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& a) {
        int n = a.size();
        if(n < 2) return;
        
        sort(a.begin(), a.end(), greater<int>());        
        int val = a[0] + 1;
        int pos = 0, mid = n / 2, x, y;
        
        for(int i = 0; i < mid; i++) {
            y = a[i] % val;            
            x = a[i + mid] % val;
            a[pos++] += x * val;            
            a[pos++] += y * val;
        }
        if(n & 1) a[pos] += val;
        
        for(int i = 0; i < n; i++) {
            a[i] /= val;
        }
    }
};