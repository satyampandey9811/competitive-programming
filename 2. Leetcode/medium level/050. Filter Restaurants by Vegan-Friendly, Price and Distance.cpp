// link to question - https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/

struct cell{
    int p, q;
};

bool comp(cell a, cell b){
    if(a.p == b.p)
        return a.q > b.q;
    return a.p > b.p;
}

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& a, int vf, int mp, int md) {
        vector<int> ans;
        vector<cell> b;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i][2] >= vf and a[i][3] <= mp and a[i][4] <= md){
                cell x;
                x.p = a[i][1];
                x.q = a[i][0];
                b.push_back(x);
            }
        }
        sort(b.begin(), b.end(), comp);
        
        for(int i = 0; i < b.size(); i++)
            ans.push_back(b[i].q);       
        
        return ans;
    }
};