// link to question - https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size(); 
        priority_queue<pair<int, int>> pq;        
        
        for(int i = 0; i < k; i++) pq.push({nums[i], i});
        
        for(int i = k; i <= n; i++) {
            auto p = pq.top();
            ans.push_back(p.first);
            
            if(i == n) break;
            
            while(pq.size() and pq.top().second < i - k + 1) pq.pop();
            pq.push({nums[i], i});            
        }
        
        return ans;
    }
};