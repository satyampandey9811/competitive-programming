// link to question - https://leetcode.com/problems/largest-perimeter-triangle/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int m=A.size();
        sort(A.begin(),A.end());
        
        while( m>=3 and A[m-3]+A[m-2]<=A[m-1]){
            m--;
        }                
        if(m==2)
            return 0;
        else
            return A[m-3]+A[m-2]+A[m-1];
        
    }
};