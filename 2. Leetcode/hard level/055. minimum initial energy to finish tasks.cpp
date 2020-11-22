// link to question - https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/

bool comp(vector<int>& a, vector<int>& b) {    
    return a[1] - a[0] > b[1] - b[0];
}

class Solution {
public:
    int minimumEffort(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), comp);
        int x = 0, y = 0, s = 0;
        
        for(int i = 0; i < a.size(); i++) {
            s += a[i][0];
            if(a[i][1] > y) {
                x += a[i][1] - y;
                y = x - s;
            }
            else {
                y = x - s;
            }
        }
        
        return x;
    }
};