// link to question - https://leetcode.com/problems/merge-intervals/

struct interval{
    int f, s;
};

bool comp(interval a, interval b){    
    return a.f < b.f;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size(), maxv = 0;
        vector<vector<int>> ans;
        vector<interval> b(n);
        
        for(int i = 0; i < n; i++){
            b[i].f = a[i][0];
            b[i].s = a[i][1];
        }
        
        sort(b.begin(), b.end(), comp);
        
        for(int i = 0; i < n; i++){
            if(i == n - 1)
                ans.push_back({b[i].f, b[i].s});      
            
            else if(b[i].s < b[i + 1].f)
                ans.push_back({b[i].f, b[i].s});
            
            else{
                int j = i + 1;
                maxv = max(b[i].s, b[j].s);
                
                while(j < n - 1 and maxv >= b[j + 1].f){
                    maxv = max(maxv, b[j + 1].s);
                    j++;
                }
                
                ans.push_back({b[i].f, maxv});
                i = j;
            }
        }
        
        return ans;
    }
};