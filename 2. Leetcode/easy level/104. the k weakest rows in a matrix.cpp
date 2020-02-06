// link to question - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& a, int k) {
        int n = a.size(), c;
        vector<int> ans;
        vector<pair<int, int>> s;
        for(int i = 0; i < n; i++){
            c = 0;
            for(int j = 0; j < a[i].size(); j++){
                if(a[i][j] == 0)
                    break;
                c++;
            }
            s.push_back({c, i});
        }
        sort(s.begin(), s.end());
        for(int i = 0; i < k; i++)
            ans.push_back(s[i].second);
        return ans;
    }
};