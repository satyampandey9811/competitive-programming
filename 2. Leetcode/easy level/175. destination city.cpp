// link to question - https://leetcode.com/problems/destination-city/

class Solution {
public:
    string destCity(vector<vector<string>>& a) {
        unordered_map<string, string> m;
        for(int i = 0; i < a.size(); i++){
            m[a[i][0]] = a[i][1];
        }
        string ans;
        for(auto x: m) {
            if(m.count(x.second) == 0) {
                ans = x.second;
                break;
            }
        }
        return ans;
    }
};