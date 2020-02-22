// link to question - https://leetcode.com/problems/non-overlapping-intervals/

bool comp(vector<int> &a, vector<int> &b){      
    return a[0] < b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size(), ans = 0;                    
        sort(a.begin(), a.end(), comp);
            
        for(int i = 0, j = 1; j < n; j++){                                   
            if(a[i][1] > a[j][0]){                               
                ans++;       
                if(a[i][1] > a[j][1])
                    i = j;                
            }            
            else i = j;
        }
        
        return ans;
    }
};