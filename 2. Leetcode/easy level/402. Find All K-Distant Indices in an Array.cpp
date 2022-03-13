// link to question - https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int key, int k) {
        int n = a.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (a[i] == key) {
                ans.push_back(i);
                continue;
            }
            int s = max(0, i - k);
            int e = min(n - 1, i + k);
            for (int j = s; j <= e; j++) {
                if (a[j] == key) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};