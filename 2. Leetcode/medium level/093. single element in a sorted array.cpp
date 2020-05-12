// link to question - https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int low = 0, high = a.size() - 1, mid;
        while(low < high) {
            mid = low + (high - low) / 2;            
            if(a[mid-1] != a[mid] and a[mid] != a[mid+1])
                return a[mid];                                    
            if(mid % 2 == 0 and a[mid-1] == a[mid])
                high = mid - 2;     
            else if(mid % 2 != 0 and a[mid] == a[mid+1])                 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return a[low];
    }
};