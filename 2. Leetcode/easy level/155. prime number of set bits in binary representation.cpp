// link to question - https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        unordered_set<int> p = {2,3,5,7,11,13,17,19,23,29,31};
        int ans = 0;
        
        for(int i = l; i <= r; i++){
            int count = 0, n = i;
            while(n){
                n = n & (n - 1);
                count++;
            }
            if(p.find(count) != p.end()) ans++;
        }
        return ans;
    }
};