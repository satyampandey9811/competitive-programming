// link to question - https://leetcode.com/problems/duplicate-zeros/

class Solution {
public:
    void duplicateZeros(vector<int>& a) {
        int n=a.size(),j=n-2;
        for(int i=0;i<n-1;){
            if(a[i]!=0)
                i++;
            else{
                while(j>=i){
                    a[j+1]=a[j];
                    j--;
                }
                i+=2;j=n-2;
            }
        }
    }
};