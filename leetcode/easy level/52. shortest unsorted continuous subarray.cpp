// link to question - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n=a.size();        
        int mini=min_element(a.begin(),a.end())-a.begin();        
        int i,j,c=0;
        if(mini!=0)
            i=0;
        else{
            for(int k=0;k<n-1;k++){
                if(a[k]<=a[k+1]){
                    
                }
                else if(a[k]>a[k+1]){
                    c=k;
                }
            }
        }
        for(int k=n-1;k>0;k--){
            if(a[k]<a[k-1]){
                j=k;
                break;
            }
        }
        return j-i+1;
    }
};