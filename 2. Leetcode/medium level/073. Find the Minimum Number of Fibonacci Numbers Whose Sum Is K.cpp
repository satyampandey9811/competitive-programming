// link to question - Find the Minimum Number of Fibonacci Numbers Whose Sum Is K

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> a(46);
        a[0] = a[1] = 1;
        int ans = 0;
        for(int i = 2; i < a.size(); i++) a[i] = a[i - 1] + a[i - 2];
        
        auto it = lower_bound(a.begin(), a.end(), k);
        if(*it == k) return 1;
        
        int dis = distance(a.begin(), it);
        
        for(int i = dis - 1; i >= 0; i--){
            while(a[i] <= k){
                k -= a[i];
                ans++;
            }
            if(k == 0) break;
        }
        
        return ans;
    }
};