// link to question - https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> a(n);
        for(int i = 0; i < n; i++) a[i] = i + 1;
        int c = 0, i = 0, d = 0;
        while(c < n - 1) {
            if(a[i] != -1) {
                d++;
                if(d == k) {
                    a[i] = -1;
                    c++;
                    d = 0;
                }
            }
            i = (i + 1) % n;
        }
        
        for(int i = 0; i < n; i++) {
            if(a[i] != -1) return i + 1;
        }
        return 0;
    }
};