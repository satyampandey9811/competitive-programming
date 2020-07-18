// link to question - https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> ans;
    
    bool dfs(vector<vector<int>>& a, vector<bool>& vis, vector<bool>& course, int x){
        if(course[x]) return 1;
        if(vis[x]) return 0;                
        vis[x] = true;
        for(int j = 0; j < a[x].size(); j++) {
            if(!dfs(a, vis, course, a[x][j]))
                return 0;
        }
        ans.push_back(x);
        course[x] = true;
        return 1;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        int x, y;        
        vector<vector<int>> a(n);
        for(int i = 0; i < pre.size(); i++) {
            x = pre[i][0], y = pre[i][1];
            a[x].push_back(y);
        }
        vector<bool> course(n, false);
        vector<bool> vis(n, false);        
        
        for(int i = 0; i < n; i++) {
            vis[i] = true; 
            if(!course[i]) {
                for(int j = 0; j < a[i].size(); j++) {
                    if(!dfs(a, vis, course, a[i][j]))
                        return {};
                }       
                ans.push_back(i);
                course[i] = true;
            }
        }
        return ans;
    }
};