// link to question - https://leetcode.com/problems/count-submatrices-with-all-ones/

class Solution {
public:    
    int numSubmat(vector<vector<int>>& a) {   
        int m = a.size(), n = a[0].size();
        vector<vector<int>> b(m, vector<int>(n));        
        
        for(int i = 0; i < m; i++) { 
            for(int j = n - 1; j >= 0; j--) { 
                if(!a[i][j]) continue; 
                if(j != n - 1) b[i][j] += b[i][j + 1]; 
                b[i][j] += a[i][j]; 
            } 
        }     
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) { 
            int j = m - 1; 
            stack<pair<int, int>> s; 
            int sum = 0; 
            while(j >= 0) { 
                int z = 0; 
                while(s.size() != 0 and s.top().first > b[j][i]) { 
                    sum -= (s.top().second + 1) * (s.top().first - b[j][i]); 
                    z += s.top().second + 1; 
                    s.pop(); 
                } 
                sum += b[j][i]; 
                ans += sum; 
                s.push({b[j][i], z}); 
                j--; 
            } 
        } 
        
        return ans; 
    }
};