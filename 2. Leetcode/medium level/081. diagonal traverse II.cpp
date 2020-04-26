// link to question - https://leetcode.com/problems/diagonal-traverse-ii/

struct cell{
    int f,s,t;
};
    
bool comp(cell a, cell b){
    if(a.f == b.f)
        return a.s > b.s;
    return a.f < b.f;
}

class Solution {
public:        
    vector<int> findDiagonalOrder(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> ans;
        vector<cell> store;
        for(int i = 0; i < n; i++){            
            for(int j = 0; j < a[i].size(); j++){
                cell temp;
                temp.f = i + j;
                temp.s = i;
                temp.t = a[i][j];
                store.push_back(temp);
            }                                                
        }
        
        sort(store.begin(), store.end(), comp);
        
        for(int i = 0; i < store.size(); i++){
            ans.push_back(store[i].t);
        }
        
        return ans;
    }
};