// link to question - https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int n = a.size(), ans = 0;
        int j = 0, t = 0, f = 0;
        
        for(int i = 0; i < n;) {
            if(a[i] == 'T') {
                if(min(t + 1, f) <= k) {
                    t++;
                    ans = max(ans, i - j + 1);
                    i++;
                }
                else {
                    if(a[j] == 'T') t--;
                    else f--;
                    j++;
                }
            }
            else {
                if(min(f + 1, t) <= k) {
                    f++;
                    ans = max(ans, i - j + 1);
                    i++;
                }
                else {
                    if(a[j] == 'F') f--;
                    else t--;
                    j++;
                }
            }
        }
        
        return ans;
    }
};