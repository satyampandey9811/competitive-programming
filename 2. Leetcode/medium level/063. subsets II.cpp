// link to question - https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(), a.end());
        set<vector<int>> res;
        vector<int> temp;
        int n = a.size();
        
        for(int i = 0; i < (1 << n); i++){
            for(int j = 0; j < n; j++){
                if(i & (1 << j))
                    temp.push_back(a[j]);
            }            
            res.insert(temp);
            temp = {};
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};