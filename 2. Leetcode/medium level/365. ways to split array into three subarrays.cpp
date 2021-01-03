// link to question - https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

class Solution {
public:
    int go(int s, int e, vector<int>& a, vector<int>& b) {
        int mid, ind = e + 1, l = s;
        while(s <= e) {
            mid = (s + e) / 2;
            if(b[mid+1] - b[l] >= b[l]) {
                ind = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ind;
    }
    
    int end(int s, int e, vector<int>& a, vector<int>& b, int left) {
        int ind = s - 1, mid;
        while(s <= e) {
            mid = (s + e) / 2;
            if(b[mid + 1] - b[left] <= b[a.size()] - b[mid + 1]) {
                ind = mid;
                s = mid + 1;
            }
            else e = mid - 1;
        }
        return ind;
    }
    
    int waysToSplit(vector<int>& a) {
        int n = a.size(), ans = 0, mod = 1e9 + 7;
        
        vector<int> b(n + 1);
        for(int i = 1; i <= n; i++) {
            b[i] = a[i-1];
            b[i] += b[i-1];
        }        
        
        for(int i = 0; i < n - 2; i++) {            
            int mid = go(i + 1, n - 2, a, b);
            if(mid == n - 1) continue;
            int midSum = b[mid+1] - b[i+1];
            int rightSum = b[n] - b[mid+1];
            if(midSum > rightSum) continue;
            
            int midEnd = end(mid + 1, n - 1, a, b, i + 1);           
            if(midEnd == n - 1) midEnd--;
            ans = (ans + midEnd - mid + 1) % mod;
        }
        
        return ans;
    }
};