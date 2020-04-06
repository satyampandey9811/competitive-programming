// link to question - https://leetcode.com/problems/count-largest-group/

class Solution {
public:
    int f(int n){
        int ans = 0;
        while(n){
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int countLargestGroup(int n) {
        int ans = 0;
        map<int, int> m;
        for(int i = 1; i <= n; i++){
            int x = f(i);
            m[x]++;
        }
        for(auto x: m){
            ans = max(ans, x.second);          
        }
        int res = 0;
        for(auto x: m){
            if(x.second == ans)
                res++;
        }
        return res;
    }
};