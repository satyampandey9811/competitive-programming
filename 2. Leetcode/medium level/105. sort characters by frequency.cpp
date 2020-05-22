// link to question - https://leetcode.com/problems/sort-characters-by-frequency/

class Solution {
public:        
    string frequencySort(string s) {
        map<char, int> m;
        for(auto i: s) m[i]++;
        priority_queue<pair<int, char>> q;
        for(auto i: m) q.push({i.second, i.first});        
        string ans;
        while(q.size() != 0) {
            auto i = q.top();
            q.pop();
            while(i.first) {
                ans += i.second;
                i.first--;
            }
        }                        
        return ans;
    }
};