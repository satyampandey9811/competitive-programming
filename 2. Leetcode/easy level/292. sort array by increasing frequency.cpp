// link to question - https://leetcode.com/problems/sort-array-by-increasing-frequency/

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        map<int, int> m;
        for(auto i: a) m[i]++;
        vector<pair<int, int>> b;
        for(auto i: m) {
            b.push_back({i.second, i.first});
        }
        sort(b.begin(), b.end(), comp);
        for(int i = 0; i < b.size(); i++) {
            for(int j = 0; j < b[i].first; j++) {
                ans.push_back(b[i].second);    
            }            
        }
        
        return ans;
    }
};