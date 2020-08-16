// link to question - https://leetcode.com/problems/magnetic-force-between-two-balls/

class Solution {
public:
    int maxDistance(vector<int>& a, int m) {    
        sort(a.begin(), a.end());   
        int low = 1, high = a.back(), mid, ans = 1, n = a.size(); 
        
        while(low <= high) {            
            mid = low + (high - low) / 2;                        
            int k = m - 1, s = a[0];                        
            
            for(int i = 1; i < n; i++) {                
                if(a[i] - s >= mid) k--, s = a[i];
            }
            
            if(k < 1) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        
        return ans;
    }
};