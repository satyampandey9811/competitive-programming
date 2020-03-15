// link to question - https://leetcode.com/problems/lucky-numbers-in-a-matrix/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& a) {
        vector<int> ans;
        int m = a.size(), n = a[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int x = *min_element(a[i].begin(), a[i].end());
                int y = 0;
                for(int k = 0; k < m; k++){
                    if(a[k][j] > y)
                        y = a[k][j];
                }
                if(x == y){
                    ans.push_back(x);
                    break;
                }
            }
        }
        return ans;
    }
};