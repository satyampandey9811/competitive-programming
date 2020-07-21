// link to question - https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& a,vector<int>& b,vector<int>&c,vector<int>&d){
        unordered_map<int, int> m;
        int n = a.size(), ans = 0, sum;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                m[a[i] + b[j]]++;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sum = c[i] + d[j];
                if(m.count(-sum)) ans += m[-sum];
            }
        }                            
        
        return ans;
    }    
};