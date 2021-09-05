// link to question - https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

bool comp(vector<int>& a, vector<int>& b) {
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;
        int mx = INT_MIN;
        sort(a.begin(), a.end(), comp);
        
        for(int i = n - 1; i >= 0; i--) {
            if(a[i][1] < mx) ans++;
            mx = max(mx, a[i][1]);
        }
        
        return ans;
    }
};