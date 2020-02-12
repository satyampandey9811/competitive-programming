// link to question - https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        map<int,vector<int>> b;
        for(int i=0;i<a.size();i++){
            b[a[i]].push_back(i);
        }
        
        for(int i=0;i<a.size();i++){
            if(a[i] * 2 == t){
                if(b.find(a[i])!=b.end() and b[a[i]].size() > 1) 
                    return  b[a[i]];
            }
            else if(b.find(t-a[i])!=b.end()){
                return {i, b[t - a[i]][0] };
            }
        }
        return {};
    }
};