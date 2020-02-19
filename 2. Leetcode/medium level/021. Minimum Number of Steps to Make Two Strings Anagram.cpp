// link to question - https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> a, b;
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++) a[s[i]]++;
        for(int i = 0; i < n; i++) b[t[i]]++;
        for(auto x: b){
            auto it = a.find(x.first);
            if(it != a.end()){
                ans += min(it -> second, x.second);
            }
        }
        return n - ans;
    }
};