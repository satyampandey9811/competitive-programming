// link to question - https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) {
        
        for(int i=0;i<a.size();i++){
            a[i]*=a[i];
        }
        sort(a.begin(),a.end());
        return a;
    }
};