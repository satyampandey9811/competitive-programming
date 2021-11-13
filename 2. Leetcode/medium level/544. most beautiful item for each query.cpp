// link to question - https://leetcode.com/problems/check-whether-a-string-contains-another-string/

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int m = items.size();
        int n = queries.size();
        sort(items.begin(), items.end());
        vector<array<int, 2>> query(n);
        
        for(int i = 0; i < n; i++) {
            query[i][0] = queries[i];
            query[i][1] = i;
        }
        sort(query.begin(), query.end());
        
        vector<int> answer(n);
        int val = 0;
        
        for(int i = 0, j = 0; i < n; i++) {
            while(j < m and items[j][0] <= query[i][0]) {
                val = max(val, items[j][1]);
                j++;
            }
            answer[query[i][1]] = val;
        }
        
        return answer;
    }
};