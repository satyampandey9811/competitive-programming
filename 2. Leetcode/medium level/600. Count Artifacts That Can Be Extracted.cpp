// link to question - https://leetcode.com/problems/count-artifacts-that-can-be-extracted/

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& a, vector<vector<int>>& dig) {
        vector<vector<bool>> vis(n, vector<bool>(n));
        for (auto &i :dig) vis[i[0]][i[1]] = true;
        int ans = 0;
        for (auto &i :a) {
            bool f = true;
            for (int j = i[0]; j <= i[2]; j++) {
                for (int k = i[1]; k <= i[3]; k++) {
                    if (!vis[j][k]) {
                        f = false;
                        break;
                    }
                }
                if (!f) break;
            }
            if (f) ans++;
        }
        return ans;
    }
};