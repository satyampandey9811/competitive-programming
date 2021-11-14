// link to question - https://leetcode.com/problems/time-needed-to-buy-tickets/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& a, int k) {
        deque<pair<int, int>> d;
        int n = a.size();
        
        for(int i = 0; i < n; i++) {
            d.push_back({a[i], i});
        }
        
        int ans = 0;
        while(d.size()) {
            auto f = d.front();
            d.pop_front();
            ans++;
            if(f.first - 1 > 0) d.push_back({f.first - 1, f.second});
            else if(f.second == k) break;
        }
        
        return ans;
    }
};