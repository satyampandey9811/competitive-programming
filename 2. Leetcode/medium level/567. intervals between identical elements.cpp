// link to question - https://leetcode.com/problems/intervals-between-identical-elements/

class Solution {
public:
    vector<long long> getDistances(vector<int>& a) {
        int mx = *max_element(a.begin(), a.end());
        mx++;
        vector<vector<int>> pos(mx);
        vector<long long> left(mx), right(mx);
        vector<int> ind(mx);
        
        int n = a.size(), val, index, diff;
        vector<long long> ans(n);
        
        for (int i = 0; i < n; i++) {
            if (pos[a[i]].size()) right[a[i]] += (i - pos[a[i]][0]);
            pos[a[i]].push_back(i);
        }
        
        for (int i = 0; i < n; i++) {
            val = a[i];
            if (right[val] == 0) continue;
            
            if (i == pos[val][0]) {
                ans[i] = right[val];
                ind[val]++;
            }
            else {
                index = ind[val];
                diff = pos[val][index] - pos[val][index-1];
                left[val] += index * diff;
                right[val] -= ((int)pos[val].size() - index) * diff;
                ans[i] = left[val] + right[val];
                ind[val]++;
            }
        }
        
        return ans;
    }
};