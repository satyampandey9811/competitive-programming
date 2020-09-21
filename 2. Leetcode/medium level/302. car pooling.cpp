// link to question - https://leetcode.com/problems/car-pooling/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size(), x, y, z;
        vector<int> a(1001);
        
        for(int i = 0; i < n; i++) {
            x = trips[i][0], y = trips[i][1], z = trips[i][2];
            a[y] += x;
            a[z] -= x;
        }
        
        for(int i = 1; i < 1001; i++) a[i] += a[i-1];
        
        for(int i = 0; i < 1001; i++) {
            if(a[i] > capacity) return 0;
        }
        
        return 1;
    }
};