// link to question - https://leetcode.com/problems/coordinate-with-maximum-network-quality/

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& a, int r) {        
        int n = a.size();
        int ans = 0;
        int x, y, sum, x1, y1, x2, y2;
        double dist;
        
        for(int i = 0; i < 51; i++) {
            for(int k = 0; k < 51; k++) {
                sum = 0;
                for(int j = 0; j < n; j++) {
                    x1 = i, y1 = k;
                    x2 = a[j][0], y2 = a[j][1];     
                    if(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) > r) continue;
                    dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));                    
                    sum += a[j][2] / (1.0 + dist);
                }
                if(sum == ans) {
                    if(i < x) x = i, y = k;
                    else if(i == x and k < y) y = k;
                }
                else if(sum > ans) {
                    ans = sum;
                    x = i, y = k;
                }                
            }
        }
        
        return {x, y};
    }
};