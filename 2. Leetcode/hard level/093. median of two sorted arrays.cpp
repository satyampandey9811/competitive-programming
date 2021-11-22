// link to question - https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedian(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        int total = m + n;
        int half = (m + n + 1) / 2;
        
        int low = 0, high = m;
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = half - cut1;
            
            int maxLeftA = (cut1 < 1) ? INT_MIN : a[cut1 - 1];
            int maxLeftB = (cut2 < 1) ? INT_MIN : b[cut2 - 1];
            int minRightA = (cut1 < m) ? a[cut1] : INT_MAX;
            int minRightB = (cut2 < n) ? b[cut2] : INT_MAX;
            
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if (total & 1) return max(maxLeftA, maxLeftB);
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            }
            
            if (maxLeftA > minRightB) high = cut1 - 1;
            else low = cut1 + 1;
        }
        
        return 0;
    }
    
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        double ans;
        
        if (m < n) ans = findMedian(a, b);
        else ans = findMedian(b, a);
        
        return ans;
    }
};