// link to question - https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        for(int i=0,j=n-1;i<j;){
            if(a[i]==0){
                int k;
                for(k=i;k<j;k++)
                    swap(a[k],a[k+1]);
                j--;
            }
            else
                i++;
        }
    }
};