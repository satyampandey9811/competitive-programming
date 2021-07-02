// link to question - https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int n = a.size();
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < n; i++) {
            if(pq.size() < k) pq.push({abs(x - a[i]), a[i]});
            else {
                if(abs(x - a[i]) < pq.top().first) {
                    pq.pop();
                    pq.push({abs(x - a[i]), a[i]});
                }
            }
        }
        
        vector<int> ans(k);
        for(int i = 0; i < k; i++) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};