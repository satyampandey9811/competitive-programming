// link to question - https://leetcode.com/problems/bag-of-tokens/

class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int p) {
        sort(a.begin(), a.end());
        int i = 0, j = a.size() - 1, ans = 0, s = 0;
        
        while(i <= j) {
            if(a[i] <= p) {
                p -= a[i];
                s++, i++;
                ans = max(ans, s);
            }            
            else if(s > 0) {
                p += a[j];
                s--, j--;
            }
            else break;            
        }
        
        return ans;
    }
};