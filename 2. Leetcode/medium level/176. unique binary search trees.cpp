// link to question - https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 0;
        vector<int> a(n + 1);
        a[1] = 1;        
                
        for(int i = 2; i <= n; i++) {
            int val = 0;
            for(int j = 1; j <= i; j++) {                                
                int x = max(1, a[j - 1]);
                int y = max(1, a[i - j]);
                val += x * y;
            }
            a[i] = val;
        }
        
        return a[n];
    }
};