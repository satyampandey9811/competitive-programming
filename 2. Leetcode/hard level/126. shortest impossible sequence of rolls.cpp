// link to question - https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/

class Solution {
public:
    int shortestSequence(vector<int>& a, int k) {
        unordered_set<int> s;
        int ans = 0;
        for (auto &i :a) {
            s.insert(i);
            if (s.size() == k) {
                ans++;
                s.clear();
            }
        }
        return ans + 1;
    }
};