// link to question - https://leetcode.com/problems/best-poker-hand/

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        set<char> s;
        for (auto &i :suits) s.insert(i);
        if (s.size() == 1) {
            return "Flush";
        }
        vector<int> a(15);
        for (auto &i :ranks) a[i]++;
        for (int i = 0; i < 15; i++) {
            if (a[i] >= 3) return "Three of a Kind";
        }
        for (int i = 0; i < 15; i++) {
            if (a[i] >= 2) return "Pair";
        }
        return "High Card";
    }
};