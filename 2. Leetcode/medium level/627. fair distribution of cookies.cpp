// link to question - https://leetcode.com/problems/fair-distribution-of-cookies/

class Solution {
public:
    int n, ans;
    
    void go (int i, vector<int>& cookies, vector<int>& assign, int k) {
        if (i == n) {
            int sum = 0;
            for (auto &j :assign) sum = max(sum, j);
            ans = min(ans, sum);
            return;
        }
        
        for (int j = 0; j < k; j++) {
            assign[j] += cookies[i];
            go (i + 1, cookies, assign, k);
            assign[j] -= cookies[i];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        ans = 1e9;
        vector<int> assign(k);
        go (0, cookies, assign, k);
        return ans;
    }
};