// link to question - https://leetcode.com/problems/prime-arrangements/

class Solution {
public:
    long long fact(int x){
        long long ans=1;
        while(x > 0){
            ans *= x;
            x--;
            ans = ans % 1000000007;
        }
        return ans;
    }
    
    int numPrimeArrangements(int n) {
        int pcnt=0;
        for(int i = 2; i <= n; i++){
            bool flag = true;
            for(int j = 2; j * j <= i; j++){
                if(i % j == 0){
                    flag = false;
                    break;
                }
            }                
            if(flag) pcnt++;
        }
        
        long long np = fact(n - pcnt), p = fact(pcnt);
        long long ans = (np % 1000000007) * (p % 1000000007);
        ans = ans % 1000000007;
        return ans;
    }
};