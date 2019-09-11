// link to question - https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n=a.size();
        if(n==0)
            return 0;
        int beg=0,pos=1;
        while(pos<n){
            if(a[beg]==a[pos])
                pos++;
            else{
                a[beg+1]=a[pos];
                beg++;pos++;
            }                
        }
        return beg+1;
    }
};