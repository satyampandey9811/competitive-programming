// link to question - https://leetcode.com/problems/distant-barcodes/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& a) {
        int n = a.size(), pos = 0;        
        unordered_map<int, int> m;
        set<pair<int, int>> s;
        
        for(int i: a) m[i]++;
        for(auto i: m) s.insert({i.second, i.first});        
                
        for(auto it = s.rbegin(); it != s.rend(); it++) {
            for(int i = 0; i < it -> first; i++, pos += 2) {
                if(pos >= n) pos = 1;
                a[pos] = it -> second;
            }
        }
        
        return a;
    }
};