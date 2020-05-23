// link to question - https://leetcode.com/problems/interval-list-intersections/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> ans;
        int i = 0, j = 0, x1, y1, x2, y2;
        
        while(i < m and j < n) {
            x1 = a[i][0], y1 = a[i][1], x2 = b[j][0], y2 = b[j][1];                     
            if(x1 > y2 or x2 > y1);
            else {
                vector<int> t = {x1, y1, x2, y2};
                sort(t.begin(), t.end());
                ans.push_back({t[1], t[2]});            
            }
            if(y1 < y2) i++;
            else if(y1 > y2) j++;
            else i++, j++;
        }
        
        return ans;
    }
};