// link to question - https://leetcode.com/problems/recover-the-original-array/

class Solution {
public:
    vector<int> recoverArray(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int diff;
        vector<int> ans;
        
        map<int, set<int>> m;
        for (int i = 0; i < n; i++) {
            m[a[i]].insert(i);
        }
        
        for (int i = 1; i < n; i++) {
            diff = a[i] - a[0];
            if (diff < 2) continue;
            
            vector<int> b(a.begin(), a.end());
            b[i] = -1;
            bool f = true;
            
            for (int j = 1; j < n; j++) {
                if (b[j] == -1) continue;
                
                if (m.count(b[j] + diff) < 1) {
                    f = false;
                    break;
                }
                
                for (auto &l :m[b[j] + diff]) {
                    if (b[l] != -1) {
                        b[l] = -1;
                        break;
                    }
                }
            }
            
            if (f) {
                for (int k = 0; k < n; k++) {
                    if (b[k] != -1) ans.push_back(b[k] + diff / 2);
                }
                break;
            }
        }
        
        return ans;
    }
};