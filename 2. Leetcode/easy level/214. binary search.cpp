// link to question - https://leetcode.com/problems/binary-search/

class Solution {
public:
    int search(vector<int>& a, int t) {
        int n=a.size();
        int i=0,j=n-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(a[mid]==t)
                return mid;
            else if(a[mid]<t)
                i=mid+1;
            else 
                j=mid-1;
        }
        return -1;
    }
};