// link to question - https://leetcode.com/problems/find-the-most-competitive-subsequence/

#define pi pair<int, int>
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& a, int k) {
        int n = a.size();
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        for(int i = 0; i <= n - k; i++) {
            pq.push({a[i], i});
        }
        
        vector<int> ans;
        int j = -1;
        
        for(int i = n - k + 1; i <= n; i++) {
            while(pq.top().second < j) pq.pop();
            ans.push_back(pq.top().first);            
            j = pq.top().second;
            pq.pop();
            if(i == n) break;
            pq.push({a[i], i});
        }
        
        return ans;
    }
};