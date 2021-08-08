// link to question - https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int c = 0, ans = 0;
        
        int i = 0, j = n - 1;
        
        while(i < j) {
            if(s[j] == '[' and s[i] == ']') {
                swap(s[i], s[j]);
                ans++;
                c++;
                i++;
            }
            else if(s[i] == '[') {
                c++;
                i++;
            }
            else if(s[i] == ']' and s[j] == ']' and c < 1) {
                j--;
            }
            else if(s[i] == ']' and c) {
                c--;
                i++;
            }
        }
        
        return ans;
    }
};