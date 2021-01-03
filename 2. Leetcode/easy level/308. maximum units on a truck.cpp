// link to question - https://leetcode.com/problems/maximum-units-on-a-truck/

bool comp(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& a, int t) {
        int n = a.size();
        int ans = 0;
        
        sort(a.begin(), a.end(), comp);

        for(int i = 0; i < n; i++) {
            int c = min(t, a[i][0]);
            ans += c * a[i][1];
            t -= c;
            if(t == 0) break;
        }
        
        return ans;
    }
};