// link to question - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        vector<int> ans;
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a[0].size(); j++)
                ans.push_back(a[i][j]);
        }
        sort(ans.begin(),ans.end());
        int c = 1;
        while(c != k){
            c++;
        }  
        return ans[c - 1];
    }
};