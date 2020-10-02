// link to question - https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void go(int pos, int sum, vector<int>& temp, vector<int>& a, int& t) {
        if(sum == t) ans.push_back(temp);                    
        else {
            for(int i = pos; i < n; i++) {
                if(sum + a[i] > t) break;
                temp.push_back(a[i]);
                go(i, sum + a[i], temp, a, t);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        n = a.size();
        vector<int> temp;
        go(0, 0, temp, a, t);
        return ans;
    }
};