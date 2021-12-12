// link to question - https://leetcode.com/problems/watering-plants-ii/

class Solution {
public:
    int minimumRefill(vector<int>& a, int ca, int cb) {
        int ans = 0;
        int n = a.size();
        
        int i = 0, j = n - 1;
        int cta = ca, ctb = cb;
        
        while (i <= j) {
            
            if (i == j) {
                if (max(cta, ctb) - a[i] < 0) {
                    ans++;
                }
                break;
            }
            
            if (cta - a[i] < 0) {
                cta = ca;
                ans++;
            }
            cta -= a[i];
            
            if (ctb - a[j] < 0) {
                ctb = cb;
                ans++;
            }
            ctb -= a[j];
            
            i++, j--;
        }
        
        return ans;
    }
};