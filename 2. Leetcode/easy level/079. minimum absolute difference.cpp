// link to question - https://leetcode.com/problems/minimum-absolute-difference/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        int mind=INT_MAX;
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]<mind) mind=a[i]-a[i-1];
        }
        for(int i=1;i<a.size();i++){
            if(a[i]-a[i-1]==mind){
                ans.push_back({a[i-1],a[i]});
            }
        }
        return ans;
    }
};