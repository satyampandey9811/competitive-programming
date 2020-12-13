// link to question - https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string a, vector<string>& w) {
        set<char> c;
        for(auto & i: a) c.insert(i);
        int ans = 0, n = w.size();
        for(int i = 0; i < n; i++) {
            bool f = true;
            for(int j = 0; j < w[i].size(); j++) {
                if(c.count(w[i][j]) == 0) {
                    f = false;
                    break;
                }
            }
            if(f) ans++;
        }
        return ans;
    }    
};