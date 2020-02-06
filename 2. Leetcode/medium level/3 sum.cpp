// link to question - https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        set<int> x(a.begin(),a.end());
        if(x.size()==1 and a.size()>2 and a[0]==0) return {{0,0,0}};
        sort(a.begin(), a.end());        
        set<vector<int>> res;
        int n = a.size();
        
        for(int i = 0; i < n - 2; i++){
            if(a[i] > 0) break;
            for(int j = i + 1; j < n - 1; j++){
                if(a[j] > abs(a[i])) break;
                int ele = -(a[i] + a[j]);
                        
                if(binary_search(a.begin() + j + 1, a.end(), ele)){
                    res.insert({a[i], a[j], ele});
                }
                
            }
        }
        vector<vector<int>> ans;
        for(auto x: res){
            ans.push_back(x);
        }
        return ans;
    }
};