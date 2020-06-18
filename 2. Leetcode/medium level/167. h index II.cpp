// link to question - https://leetcode.com/problems/h-index-ii/

class Solution {
public:
    int hIndex(vector<int>& a) {
        ios::sync_with_stdio(false), cin.tie(0);
        int n = a.size();
        int low = 0, high = n - 1, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(a[mid] >= n - mid) high = mid - 1;
            else low = mid + 1;
        }                            
        return n - low;       
    }
};