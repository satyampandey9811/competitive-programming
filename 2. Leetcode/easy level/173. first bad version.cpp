// link to question - https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n, mid;
        int ans;
        while(low <= high){
            mid = low + (high - low) / 2;
            bool ver = isBadVersion(mid);
            if(!ver) low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};