// link to question - https://leetcode.com/problems/find-k-th-smallest-pair-distance/

class Solution {
public:
    int smallestDistancePair(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        int low = 0, mid, high = a.back() - a[0];
        
        while(low < high) {
            mid = low + (high - low) / 2;
            int c = 0;            
            for(int i = 0, j = 1; i < n; i++) {
                while(j < n and a[j] - a[i] <= mid) j++;
                c += j - i - 1;
            }
            
            if(c < k) low = mid + 1;
            else high = mid;
        }
        
        return low;
    }
};