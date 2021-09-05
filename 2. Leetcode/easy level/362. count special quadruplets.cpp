// link to question - https://leetcode.com/problems/count-special-quadruplets/

class Solution {
public:
    int countQuadruplets(vector<int>& a) {
        int ans = 0, n = a.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    for(int l = k + 1; l < n; l++) {
                        if(a[i] + a[j] + a[k] == a[l]) ans++;
                    }
                }
            }
        }
        return ans;
    }
};