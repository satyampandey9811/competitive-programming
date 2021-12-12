// link to question - https://leetcode.com/problems/rings-and-rods/

class Solution {
public:
    int countPoints(string a) {
        vector<array<bool, 3>> b(10);
        int n = a.size();
        
        for (int i = 0; i < n; i += 2) {
            if (a[i] == 'R') {
                b[a[i+1] - '0'][0] = true;
            }
            else if (a[i] == 'G') {
                b[a[i+1] - '0'][1] = true;
            }
            else {
                b[a[i+1] - '0'][2] = true;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            if (b[i][0] and b[i][1] and b[i][2]) ans++;
        }
        return ans;
    }
};