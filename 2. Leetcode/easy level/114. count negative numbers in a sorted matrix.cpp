// link to question - https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int ans = 0;
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++){
                if(a[i][j] < 0)
                    ans++;
            }
        }
        return ans;
    }
};