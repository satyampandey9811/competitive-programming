// link to question - https://leetcode.com/problems/maximum-repeating-substring/

class Solution {
public:
    int maxRepeating(string a, string b) {
        int m = a.size(), n = b.size(), ans = 0, c = 0, j = -1;
        for(int i = 0; i <= m - n; ) {
            if(a.substr(i, n) == b) {
                if(i - 1 == j) c++;
                else c = 1;
                j = i + n - 1;
                i += n;
            }
            else i++;
            ans = max(ans, c);
        }
        return ans;
    }
};