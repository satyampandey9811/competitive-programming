// link to question - https://leetcode.com/problems/percentage-of-letter-in-string/

class Solution {
public:
    int percentageLetter(string s, char l) {
        int n = s.size();
        int c = 0;
        
        for (auto &i :s) {
            if (i == l) c++;
        }
        
        int ans = c * 100 / n;
        return ans;
    }
};