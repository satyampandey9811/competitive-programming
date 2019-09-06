// link to question - https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& a) {
        
        int n=a.size(),sum=0;
        vector<int> b(n);
        
        for(int j=0;j<A.size();j++){
                if(A[j]%2==0)
                    sum+=A[j];
            }
        
        for(int i=0;i<n;i++){
            
            int x=a[i][0],y=a[i][1];
            
            if(A[y]%2==0)
                sum-=A[y];
            A[y]+=x;
            if(A[y]%2==0)
                sum+=A[y];
            
            b[i]=sum;
        }
        return b;
    }
};