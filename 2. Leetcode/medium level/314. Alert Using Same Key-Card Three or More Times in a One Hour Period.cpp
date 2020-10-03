// link to question - Alert Using Same Key-Card Three or More Times in a One Hour Period

class Solution {
public:
    vector<string> alertNames(vector<string>& a, vector<string>& t) {
        unordered_map<string, vector<int>> m;
        
        int n = a.size(), time, h, min;
        for(int i = 0; i < n; i++) {
            h = stoi(t[i].substr(0, 2)) * 60;
            min = stoi(t[i].substr(3));
            m[a[i]].push_back(h + min);
        }
        
        for(auto &i: m) {
            sort(i.second.begin(), i.second.end());
        }
        
        vector<string> ans;
        
        for(auto i: m) {
            if(i.second.size() > 2) {
                for(int j = 2; j < i.second.size(); j++) {
                    if(i.second[j] - i.second[j-2] < 61) {
                        ans.push_back(i.first);
                        break;
                    }
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};