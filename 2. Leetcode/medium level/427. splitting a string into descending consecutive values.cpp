// link to question - https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/

class Solution {
public:
    int n;
    
    bool check(string& s, long long number, int i, int count) {
        if(i == n) {
            if(count > 1) return 1;
            return 0;
        }
        
        long long p = 0;
        
        for(int j = i; j < n; j++) {
            p = p * 10 + s[j] - '0';
            
            if(p > 1e10) return 0;
            if(number == -100 and check(s, p, j + 1, count + 1)) return 1;
            if(p == number - 1 and check(s, p, j + 1, count + 1)) return 1;
        }
        
        return 0;
    }
    
    bool splitString(string s) {
        n = s.size();
        return check(s, -100, 0, 0);
    }
};