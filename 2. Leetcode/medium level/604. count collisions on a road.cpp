// link to question - https://leetcode.com/problems/count-collisions-on-a-road/

class Solution {
public:
    int countCollisions(string a) {
        int n = a.size(), ans = 0;
        int i = 0, j = n - 1;
        
        while (i < n and a[i] == 'L') i++;
        while (j >= 0 and a[j] == 'R') j--;
        
        while (i <= j) {
            if (a[i] == 'L' or a[i] == 'R') ans++;
            i++;
        }
        
        return ans;
    }
};