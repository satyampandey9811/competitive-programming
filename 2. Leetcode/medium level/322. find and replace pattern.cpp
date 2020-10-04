// link to question - https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& a, string p) {
        vector<string> ans;   
        int n = a.size();
        unordered_map<char, char> m;
        unordered_set<char> s;
        bool f;
        
        for(int i = 0; i < n; i++) {
            if(a[i].size() != p.size()) continue;
            f = true;
                        
            for(int j = 0; j < a[i].size(); j++) {
                if(m.count(p[j]) == 0) {
                    m[p[j]] = a[i][j];
                    if(s.count(a[i][j])) {
                        f = false;
                        break;
                    }
                    else s.insert(a[i][j]);
                }
                else {
                    if(m[p[j]] != a[i][j]) {
                        f = false;
                        break;
                    }                    
                }
            }            
            m.clear();
            s.clear();
            if(f) ans.push_back(a[i]);
        }
        
        return ans;
    }
};