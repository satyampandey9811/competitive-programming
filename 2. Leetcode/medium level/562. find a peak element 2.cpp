// link to question - https://leetcode.com/problems/find-a-peak-element-ii/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& a) {
        vector<int> answer(2);
        int m = a.size(), n = a[0].size(), i = 0, j = 0;
        int val, up, down, left, right, mx;
        
        while (i < m and j < n and i >= 0 and j >= 0) {
            val = a[i][j];
            up = (i > 0) ? a[i-1][j] : -1;
            down = (i + 1 < m) ? a[i+1][j] : -1;
            left = (j > 0) ? a[i][j-1] : -1;
            right = (j + 1 < n) ? a[i][j+1] : -1;
            
            mx = max({up, down, left, right});
            
            if (val > mx) {
                answer[0] = i, answer[1] = j;
                break;
            }
            
            if (mx == up) i--;
            else if (mx == down) i++;
            else if (mx == left) j--;
            else j++;
        }
        
        return answer;
    }
};