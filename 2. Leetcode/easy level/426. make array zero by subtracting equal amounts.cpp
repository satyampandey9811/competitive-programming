// link to question - https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/

class Solution {
public:
    int minimumOperations(vector<int>& a) {
        set<int> st(a.begin(), a.end());
        if (st.count(0) < 1) {
            return st.size();
        }
        int ans = st.size() - 1;
        return ans;
    }
};