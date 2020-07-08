// link to question - https://leetcode.com/problems/top-k-frequent-elements/

typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        unordered_map<int, int> m;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(int i: nums) m[i]++;        
        for(auto i: m) {
            pq.push({i.second, i.first});
            if(pq.size() > k) pq.pop();
        }       
        for(int i = 0; i < k; i++) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};