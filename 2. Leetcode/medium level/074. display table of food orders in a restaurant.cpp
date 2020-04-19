// link to question - https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& a) {
                
        map<pair<string, string>, int> mp;        
        set<string> items;
        set<int> table;        
        string x, y;
        
        for(int i = 0; i < a.size(); i++){
            x = a[i][1], y = a[i][2];
            items.insert(y);
            table.insert(stoi(x));
            mp[{x, y}]++;
        }
                                
        vector<vector<string>> ans(table.size() + 1, vector<string>(items.size() + 1));
        ans[0][0] = "Table";
        int c = 1;
        for(auto x: items) ans[0][c++] = x;                    
        c = 1;
        for(auto x: table) ans[c++][0] = to_string(x);                 
        
        for(int i = 1; i < ans.size(); i++){
            for(int j = 1; j < ans[0].size(); j++){                
                x = ans[i][0], y = ans[0][j];
                ans[i][j] = to_string(mp[{x, y}]);
            }
        }        
        
        return ans;
    }
};