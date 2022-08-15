// link to question - https://leetcode.com/problems/largest-local-values-in-a-matrix/

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& a) {
        int n = a.size(), val;
        vector<vector<int>> b(n - 2);
        
        for (int i = 0; i < n - 2; i++) {
            vector<int> d;
            
            for (int j = 0; j < n - 2; j++) {
                val = 0;
                
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        val = max(val, a[k][l]);
                    }
                }
                d.push_back(val);
            }
            
            b[i] = d;
        }
        
        return b;
    }
};