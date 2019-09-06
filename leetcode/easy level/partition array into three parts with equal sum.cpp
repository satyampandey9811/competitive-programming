// link to question - https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

class Solution {
public:
    
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=accumulate(A.begin(),A.end() ,0);
        if(sum%3!=0)
            return false;
        int i=0,n=A.size();
        int p=0,q=0,r=0;
        while(p<sum/3 and i<n){
            p+=A[i];i++;
        }
        while(q<sum/3 and i<n){
            q+=A[i];i++;
        }
        while(r<sum/3 and i<n){
            r+=A[i];i++;
        }
        if(p==q and p==r)
            return true;
        else 
            return false;
    }
};