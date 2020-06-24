// link to question - https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n == 1) return 0;
        int i = 0, j = n - 1, mid;
        
        while(i <= j) {
            mid = i + (j - i) / 2;
            if(mid > 0 and mid < n - 1) {
                if(a[mid] > a[mid-1] and a[mid] > a[mid+1])
                    return mid;
                else if(a[mid-1] > a[mid])
                    j = mid - 1;
                else i = mid + 1;
            }
            else if(mid == 0) {
                if(a[0] > a[1])
                    return 0;
                return 1;
            }
            else {
                if(a[n-1] > a[n-2])
                    return n - 1;
                return n - 2;
            }
        }
        
        return 0;
    }
};