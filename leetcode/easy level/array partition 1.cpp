// link to question - https://leetcode.com/problems/array-partition-i/

class Solution {
public:
    int arrayPairSum(vector<int>& a) {
        
        int n=a.size(),sum=0;
        sort(a.begin(),a.end());        
        for(int i=0;i<n;i+=2)
            sum+=a[i];
        return sum;
    }
};