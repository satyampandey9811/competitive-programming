// link to question - https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    int find(vector<int>& bloom, int day, int k) {
        int ans = 0, count = 0;    
        for(int i = 0; i < bloom.size(); i++) {
            if(bloom[i] <= day) count++;
            else count = 0;
            if(count == k) {
                ans++;
                count = 0;
            }
        }
        return ans;
    }
    
    int minDays(vector<int>& bloom, int m, int k) {
        if(1LL * m * k > bloom.size()) return -1;
        
        auto p = minmax_element(bloom.begin(), bloom.end());
        int i = *p.first, j = *p.second, mid;
        
        while(i <= j) {
            mid = (i + j) / 2;
            if(find(bloom, mid, k) < m)
                i = mid + 1;
            else 
                j = mid - 1;
        }
        
        return i;
    }
};