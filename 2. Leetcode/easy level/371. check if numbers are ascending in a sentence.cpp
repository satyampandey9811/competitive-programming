// link to question - https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/

class Solution {
public:
    bool areNumbersAscending(string s) {
        int first = -1, num = 0;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                if(num and first == -1) first = num;
                else if(num and first >= num) return 0;
                else if(num) first = num;
                num = 0;
                continue;
            }
            if(s[i] >= 'a' and s[i] <= 'z') continue;
            num = num * 10 + (s[i] - '0');
        }
        if(num and first >= num) return 0;
        
        return 1;
    }
};