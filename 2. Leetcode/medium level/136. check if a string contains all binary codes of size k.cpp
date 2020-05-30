// link to question - https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(k > n) return 0;
        string a;
        int j = 0;
        unordered_set<string> u;
        for(int i = 0; i < n; i++) {
            a = s[i] + a;
            if(a.size() == k) {
                u.insert(a);
                a.pop_back();
            }
        }
        if(u.size() == pow(2, k)) return 1;
        return 0;
    }
};