// link to question - https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

struct pairs{
  int first, second;  
};

bool comp(pairs a, pairs b){         
    return a.first + a.second < b.first + b.second;
}

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) { 
        int m = a.size(), n = b.size(), num = 0;
        vector<vector<int>> ans;
        vector<pairs> c(m * n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                c[num].first = a[i];
                c[num].second = b[j];
                num++;
            }
        }
        sort(c.begin(), c.end(), comp);
        for(int i = 0; i < k and i < c.size(); i++)
            ans.push_back({c[i].first, c[i].second});
        return ans;
    }
};