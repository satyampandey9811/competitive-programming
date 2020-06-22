// link to question - https://leetcode.com/problems/making-file-names-unique/

class Solution {
public:
    vector<string> getFolderNames(vector<string>& a) {
        vector<string> ans;
        int n = a.size();
        
        unordered_map<string, int> m;
        
        for(int i = 0; i < n; i++) {
            if(m.count(a[i]) == 0) {
                m[a[i]] = 0;                   
                ans.push_back(a[i]);
            }
            else {
                for(int j = m[a[i]] + 1; ; j++) {
                    string t = a[i] + "(" + to_string(j) + ")";
                    if(m.count(t) == 0) {
                        m[a[i]] = j;
                        m[t] = 0;
                        ans.push_back(t);
                        break;
                    }
                }
            }               
        }
        
        return ans;
    }
};