// link to question - https://leetcode.com/problems/four-divisors/

class Solution {
public:
    int sumFourDivisors(vector<int>& a) {
        int ans = 0, csum;
        int n = a.size(), x, c;
        
        for(int i = 0; i < n; i++){
            x = a[i];
            csum = 0, c = 0;
            for(int i = 1; i * i <= x; i++){
                if(x % i == 0){                    
                    csum += i;
                    c++;
                    if(i != x/i){
                        csum += x/i;
                        c++;
                    }
                }
                if(c > 4)
                    break;
            }
            if(c == 4)
                ans += csum;
        }
        
        return ans;
    }
};