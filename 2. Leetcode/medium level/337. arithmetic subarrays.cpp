// link to question - https://leetcode.com/problems/arithmetic-subarrays/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        int n = a.size();    

        vector<bool> ans(l.size());
        for(int i = 0; i < l.size(); i++) {
            int x = l[i], y = r[i];
            bool f = true;
            vector<int> b(a.begin() + x, a.begin() + y + 1);
            sort(b.begin(), b.end());
            int z = b[1] - b[0];
            for(int j = 1; j < b.size(); j++) {
                if(b[j] - b[j-1] != z) {
                    f = false;
                    break;
                }
            }
            ans[i] = f;
        }

        return ans;
    }
};