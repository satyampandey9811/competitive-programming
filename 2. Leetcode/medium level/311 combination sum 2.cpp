// link to question - https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void go(int start, int sum, int& t, vector<int>& temp, vector<int>& a) {
        if(sum == t) ans.push_back(temp);        
        else {
            for(int i = start; i < n; i++) {                
                if(i != start and a[i] == a[i-1]) continue;
                
                if(sum + a[i] > t) break;
                temp.push_back(a[i]);
                go(i + 1, sum + a[i], t, temp, a);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        n = a.size();
        sort(a.begin(), a.end());
        vector<int> temp;
        go(0, 0, t, temp, a);
        return ans;
    }
};