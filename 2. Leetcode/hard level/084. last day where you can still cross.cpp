// link to question - https://leetcode.com/problems/last-day-where-you-can-still-cross/

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cell) {
        int ans = 0;
        int low = 1, high = row * col, mid;
        int r, c;
        
        vector<vector<int>> a(row, vector<int>(col));
        vector<vector<bool>> vis(row, vector<bool>(col));
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            bool g = false;
            
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    vis[i][j] = false;
                    a[i][j] = 0;
                }
            }
            
            for(int i = 0; i < mid; i++) {
                r = cell[i][0], c = cell[i][1];
                a[r-1][c-1] = 1;
            }
            
            queue<int> qr, qc;
            
            for(int i = 0; i < col; i++) {
                if(a[0][i] == 0) {
                    qr.push(0);
                    qc.push(i);
                    vis[0][i] = true;
                }
            }
            
            while(qr.size()) {
                bool f = true;
                for(int z = qr.size(); z > 0; z--) {
                    r = qr.front();
                    c = qc.front();
                    qr.pop();
                    qc.pop();
                    
                    if(r == row - 1) {
                        ans = mid;
                        low = mid + 1;
                        f = false;
                        break;
                    }
                    
                    if(r-1 >= 0 and !vis[r-1][c] and a[r-1][c] == 0) {
                        qr.push(r - 1);
                        qc.push(c);
                        vis[r-1][c] = true;
                    }
                    
                    if(r+1 < row and !vis[r+1][c] and a[r+1][c] == 0) {
                        if(r + 1 == row - 1) {
                            ans = mid;
                            low = mid + 1;
                            f = false;
                            break;
                        }
                        qr.push(r + 1);
                        qc.push(c);
                        vis[r+1][c] = true;
                    }
                    
                    if(c-1 >= 0 and !vis[r][c-1] and a[r][c-1] == 0) {
                        qr.push(r);
                        qc.push(c - 1);
                        vis[r][c-1] = true;
                    }
                    
                    if(c+1 < col and !vis[r][c+1] and a[r][c+1] == 0) {
                        qr.push(r);
                        qc.push(c + 1);
                        vis[r][c+1] = true;
                    }
                }
                
                if(!f) {
                    g = true;
                    break;
                }
            }
            
            if(!g) high = mid - 1;
        }
        
        return ans;
    }
};