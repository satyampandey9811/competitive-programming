// link to question - https://leetcode.com/problems/cinema-seat-allocation/

#include<unordered_set>
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        int ans = 0;
        map<int, vector<int>> mp;
        int m = a.size();
        
        for(int i = 0; i < m; i++){
            if(a[i][1] > 1 and a[i][1] < 10){
                mp[a[i][0]].resize(10);
                mp[a[i][0]][a[i][1]] = 1;
            }
        }
            
        ans += (n - mp.size()) * 2;
            
        for(auto x: mp){
            ans += 2;
            if(x.second[4] == 1 or x.second[5] == 1){
                ans--;
                if(x.second[6] == 1 or x.second[7] == 1 or x.second[8] == 1 or x.second[9] == 1)
                    ans--;          
            }
            else if(x.second[6] == 1 or x.second[7] == 1){
                ans--;
                if(x.second[2] == 1 or x.second[3] == 1 or x.second[4] == 1 or x.second[5] == 1)
                    ans--;
            }
            else
                ans--;
        }
        return ans;
    }
};