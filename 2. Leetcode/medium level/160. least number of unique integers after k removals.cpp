// link to question - https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        map<int, int> m;
        for(int i: a) m[i]++;
        vector<pair<int, int>> v;
        
        for(auto i: m) {
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end());
        
        int c = 0;
        
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first > k) {
                break;
            }
            else k -= v[i].first, c++;
        }
        
        return v.size() - c;
    }
};