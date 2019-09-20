// link to question - https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& a, int t) {
        int low=0,high=a.size()-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(a[mid]==t)
                return mid;
            else if(a[mid]<=a[high]){
                if(a[mid]<t and t<=a[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
            else{
                if(a[low]<=t and t<a[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
        }
        return -1;
    }
};