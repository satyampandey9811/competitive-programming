// link to question - https://leetcode.com/problems/queries-on-a-permutation-with-key/

class Solution {
public:
    vector<int> processQueries(vector<int>& a, int m) {
        vector<int> ans;
        map<int, int> p;
        map<int, int> q;
        int n = a.size(), x, y, z;
        for(int i = 0; i < m; i++) p[i + 1] = i;
        for(int i = 0; i < m; i++) q[i] = i + 1;
        
        for(int i = 0; i < n; i++){
            x = p[a[i]];
            ans.push_back(x); 
            for(int j = x; j > 0; j--){                
                y = j;
                z = q[j - 1];
                q[j] = z;
                p[z] = y;
            }
            p[a[i]] = 0;
            q[0] = a[i];
        }
        return ans;
    }
};