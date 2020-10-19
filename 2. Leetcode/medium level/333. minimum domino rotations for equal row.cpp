// link to question - https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        vector<int> c(7), d(7), e(7);
        int n = a.size();
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(a[i] == 1 or b[i] == 1) {
                c[1]++;
                if(a[i] == 1) d[1]++;
                if(b[i] == 1) e[1]++;
            }
            if(a[i] == 2 or b[i] == 2) {
                c[2]++;
                if(a[i] == 2) d[2]++;
                if(b[i] == 2) e[2]++;
            }
            if(a[i] == 3 or b[i] == 3) {
                c[3]++;
                if(a[i] == 3) d[3]++;
                if(b[i] == 3) e[3]++;
            }            
            if(a[i] == 4 or b[i] == 4) {
                c[4]++;
                if(a[i] == 4) d[4]++;
                if(b[i] == 4) e[4]++;
            }
            if(a[i] == 5 or b[i] == 5) {
                c[5]++;
                if(a[i] == 5) d[5]++;
                if(b[i] == 5) e[5]++;
            }
            if(a[i] == 6 or b[i] == 6) {
                c[6]++;
                if(a[i] == 6) d[6]++;
                if(b[i] == 6) e[6]++;
            }        
        }
        
        bool f = false;        
        for(int i = 1; i < 7; i++) {
            if(c[i] < n) continue;
            f = true;
            ans = min(ans, n - max(d[i], e[i]));
        }
        
        return f ? ans : -1;
    }
};