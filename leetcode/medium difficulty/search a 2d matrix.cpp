// link to question - https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        
        if(a.size()==0)
            return false;        
        for(int i=0;i<a.size();i++){
            int j=0,k=a[0].size()-1,mid;
            while(j<=k){
                mid=(j+k)/2;
                if(a[i][mid]==t)
                    return true;
                else if(a[i][mid]>t)
                    k=mid-1;
                else
                    j=mid+1;
            }
        }
        return false;
    }
};