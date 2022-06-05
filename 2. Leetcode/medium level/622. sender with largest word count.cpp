// link to question - https://leetcode.com/problems/sender-with-largest-word-count/

class Solution {
public:
    string largestWordCount(vector<string>& m, vector<string>& s) {
        map<string, int> mps;
        int n = s.size(), c = 0;
        vector<string> ans;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m[i].size(); j++) if (m[i][j] == ' ') sum++;
            sum++;
            mps[s[i]] += sum;
        }
        
        for (auto &i :mps) c = max(c, i.second);
        
        for (auto &i :mps) {
            if (i.second == c) {
                ans.push_back(i.first);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans.back();
    }
};