// link to question - https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/


class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> row(mat[0]);
        for(int i = 1; i < mat.size(); i++) {
            vector<int> temp;
            for(int j = 0; j < mat[i].size(); j++) {
                for(auto k: row) {
                    temp.push_back(mat[i][j] + k);
                }
            }
            sort(temp.begin(), temp.end());
            temp.resize(min(k, (int)temp.size()));
            row = move(temp);
        }
        return row[k - 1];
    }
};