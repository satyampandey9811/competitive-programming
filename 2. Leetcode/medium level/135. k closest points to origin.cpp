// link to question - https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:        
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y){
            return x[0]*x[0] + x[1]*x[1] < y[0]*y[0] + y[1]*y[1]; 
        });
        a.resize(k);
        return a;
    }
};