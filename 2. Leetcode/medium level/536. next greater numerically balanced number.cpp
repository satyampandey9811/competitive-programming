// link to question - https://leetcode.com/problems/next-greater-numerically-balanced-number/

class Solution {
public:
    int ans;
    
    void go(int n, string s) {
        int num;
        do {
            num = stoi(s);
            if(num > n) ans = min(ans, num);
        } while(next_permutation(s.begin(), s.end()));
    }
    
    int nextBeautifulNumber(int n) {
        if(n == 0) return 1;
        int dig = 0;
        int num = n;
        ans = INT_MAX;
        
        while(num) {
            dig++;
            num /= 10;
        }
        
        if(n < 22) return 22;
        if(dig == 2) {
            go(n, "22");
            go(n, "122");
            go(n, "333");
        }
        else if(dig == 3) {
            go(n, "122");
            go(n, "333");
            go(n, "1333");
        }
        else if(dig == 4) {
            go(n, "1333");
            go(n, "4444");
            go(n, "14444");
        }
        else if(dig == 5) {
            go(n, "14444");
            go(n, "22333");
            go(n, "55555");
            go(n, "122333");
        }
        else if(dig == 6) {
            go(n, "122333");
            go(n, "155555");
            go(n, "224444");
            go(n, "666666");
            go(n, "1224444");
        }
        else if(dig == 7) {
            go(n, "1224444");
            go(n, "1666666");
            go(n, "2255555");
            go(n, "3334444");
            go(n, "7777777");
            go(n, "12255555");
        }
        
        return ans;
    }
};