// link to question - https://leetcode.com/problems/top-k-frequent-words/

class comp {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans(k);
        unordered_map<string, int> m;
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
        for(auto i: words) m[i]++;        
        for(auto i: m) {
            pq.push({i.first, i.second});
            if(pq.size() > k) pq.pop();
        }        
        for(int i = 0; i < k; i++) {
            ans[i] = pq.top().first;     
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};