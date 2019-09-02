// link to question - https://leetcode.com/problems/maximum-product-of-three-numbers/

class Solution {
public:
    int maximumProduct(vector<int>& a) {
        int n=a.size();        
        sort(a.begin(),a.end());
        
        int ans=INT_MIN;
        ans=max(a[n-1]*a[n-2]*a[n-3],a[0]*a[1]*a[2]);
        ans=max(ans,a[0]*a[1]*a[n-1]);
        
        return ans;
        
    }
};