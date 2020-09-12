// link to question - https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    int sum, k;
    vector<int> a;
    vector<vector<int>> ans;
    
    void go(int i, int num, int s, vector<int> temp) {        
        if(s == sum and num == k) {
            ans.push_back(temp);
            return;
        }
        if(i == 9) return;
        
        go(i + 1, num, s, temp);
        if(a[i] > sum - s) return;
        temp.push_back(a[i]);
        go(i + 1, num + 1, s + a[i], temp);
    }
    
    vector<vector<int>> combinationSum3(int k1, int n) {
        sum = n, k = k1;        
        a.resize(9);
        for(int i = 0; i < 9; i++) a[i] = i + 1;
        
        vector<int> temp;
        go(0, 0, 0, temp);
        return ans;
    }
};