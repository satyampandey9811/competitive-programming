// link to question - https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& a) {
        int n=a.size();
        int c=0;
        
        map<pair<int,int>,int> mp;
        
        for(int i=0;i<n;i++){
            if(a[i][0] > a[i][1]) swap(a[i][0], a[i][1]);
            mp[{a[i][0],a[i][1]}]++;
        }
        //for(auto x: mp) cout << x.first.first <<' '<<x.first.second<<' '<<x.second<<'\n';
        for(auto x: mp) c += (x.second * (x.second - 1))/2;
        
        return c;
    }
};