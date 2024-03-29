// link to question - https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

class Solution {
public:
    int minMovesToSeat(vector<int>& a, vector<int>& b) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += abs(a[i] - b[i]);
        }
        
        return ans;
    }
};