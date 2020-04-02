// link to question - https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = a.size();
        
        for(int i = 0; i < (1 << n); i++){
            for(int j = 0; j < n; j++){
                if(i & (1 << j))
                    temp.push_back(a[j]);
            }
            ans.push_back(temp);
            temp = {};
        }
        return ans;
    }
};