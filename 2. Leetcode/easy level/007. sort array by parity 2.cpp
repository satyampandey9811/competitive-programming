// link to question - https://leetcode.com/problems/sort-array-by-parity-ii/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        
        int n=a.size(),j=0,k=1;
        vector<int> b(n);
        for(int i=0;i<n;i++){
            if(a[i]%2==0){
                b[j]=a[i];
                j+=2;
            }
            else{
                b[k]=a[i];
                k+=2;
            }
        } 
        return b;
    }
};