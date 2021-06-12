// link to question - https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

class Solution {
public:
    int chalkReplacer(vector<int>& a, int k) {
        int n = a.size();
        
        long long sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
        
        long long x = (long long)k % sum;
        
        for(int i = 0; i < n; i++) {
            if(a[i] > x) return i;
            x -= a[i];
        }
        
        return 0;
    }
};