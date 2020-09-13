// link to question - https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& iv, vector<int>& ni) {
        vector<vector<int>> ans;
        int n = iv.size();

        int s = ni[0], e = ni[1];
        
        for(int i = 0; i < n; i++) {
            if(s >= iv[i][0] and s <= iv[i][1]) {
                s = iv[i][0];
                break;
            }
        }
        
        for(int i = n - 1; i >= 0; i--) {
            if(e >= iv[i][0] and e <= iv[i][1]) {
                e = iv[i][1];
                break;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(iv[i][0] >= s) break;
            ans.push_back(iv[i]);
        }
        
        ans.push_back({s, e});
        
        for(int i = 0; i < n; i++) {
            if(iv[i][0] > e) ans.push_back(iv[i]);
        }
        
        return ans;
    }
};