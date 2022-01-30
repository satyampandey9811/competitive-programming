// link to question - https://leetcode.com/problems/keep-multiplying-found-values-by-two/

class Solution {
public:
    int findFinalValue(vector<int>& a, int v) {
        set<int> s(a.begin(), a.end());
        while (1) {
            if (s.count(v)) {
                v *= 2;
            }
            else break;
        }
        return v;
    }
};