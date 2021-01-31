// link to question - https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        int n = ap.size();
        vector<int> a(n + 1);
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[ap[i][0]]++;
            m[ap[i][1]]++;
        }
        
        int f = 1e6, s;
        for(auto& i: m) {
            if(i.second == 1 and f == 1e6) f = i.first;
            else if(i.second == 1 and f != 1e6) s = i.first;
        }
        
        a[0] = f, a[n] = s;
        
        map<int, vector<int>> mp;
        
        for(int i = 0; i < n; i++) {
            mp[ap[i][0]].push_back(ap[i][1]);
            mp[ap[i][1]].push_back(ap[i][0]);
        }
        
        for(int i = 1; i < n; i++) {
            if(i == 1) a[i] = mp[a[i-1]][0];
            else if(i == n - 1) a[i] = mp[a[i+1]][0];
            else {
                int x = mp[a[i-1]][0], y = mp[a[i-1]][1];
                if(a[i-2] == x) a[i] = y;
                else a[i] = x;
            }
        }
        
        return a;
    }
};