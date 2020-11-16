// link to question - https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& a) {
        int n = a.size(), ans = 0;
        int c = 1;
        bool inc = false, dec = false;
        
        for(int i = 1; i < n; i++) {
            if(a[i] > a[i-1] and !dec) {
                c++;
                inc = true;
            }
            if(a[i] > a[i-1] and dec) {
                c = 2;
                inc = true;
                dec = false;
            }
            if(a[i] == a[i-1]) {
                c = 1;
                inc = dec = false;
            }
            if(a[i] < a[i-1] and inc) {
                dec = true;
                c++;
            }
            if(a[i] < a[i-1] and !inc) {
                c = 1;
                inc = dec = false;
            }
            if(inc and dec) ans = max(ans, c);
        }
        
        return ans;
    }
};