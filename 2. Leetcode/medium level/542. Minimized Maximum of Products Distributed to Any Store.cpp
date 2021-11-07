// link to question - https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/

class Solution {
public:
    int m;
    
    bool check(int &n, int &val, vector<int>& a) {
        int c = 0;
        for(int i = 0; i < m; i++) {
            c += a[i] / val;
            if(a[i] % val) c++;
            if(c > n) return 0;
        }
        return 1;
    }
    
    int minimizedMaximum(int n, vector<int>& a) {
        m = a.size();
        int low = 1, mid, high = *max_element(a.begin(), a.end()), ans;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            
            if(check(n, mid, a)) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return ans;
    }
};