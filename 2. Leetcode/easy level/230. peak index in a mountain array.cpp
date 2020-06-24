// link to question - https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int s = 1, e = a.size() - 2, mid;
        
        while(s <= e) {
            mid = s + (e - s) / 2;
            if(a[mid] > a[mid-1] and a[mid] > a[mid+1])
                return mid;
            else if(a[mid] < a[mid+1])
                s = mid + 1;
            else 
                e = mid - 1;
        }
        
        return 0;
    }
};