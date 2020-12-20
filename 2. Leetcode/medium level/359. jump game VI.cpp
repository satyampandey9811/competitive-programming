// link to question - https://leetcode.com/problems/jump-game-vi/

class Solution {
public:    
    int maxResult(vector<int>& a, int k) {
        int n = a.size();
        
        priority_queue<pair<int, int>> pq;
        pq.push({a[n-1], n-1});
        int val, ans = a[0];
        
        for(int i = n-2; i >= 0; i--) {
            while(pq.size() and pq.top().second > i + k) pq.pop();
            val = pq.top().first;            
            pq.push({a[i] + val, i});
            if(i == 0) ans = a[i] + val;
        }
        
        return ans;
    }
};