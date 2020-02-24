// link to question - https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

class Solution {
public:
    vector<int> sortByBits(vector<int>& a) {
        map<int, vector<int>> m;
        int n = a.size();
        for(int i = 0; i < n; i++){
            int x = a[i], c = 0;
            while(x > 0){
                if(x % 2 == 1)
                    c++;
                x /= 2;
            }
            m[c].push_back(a[i]);
        }
        vector<int> ans;
        for(auto x: m){
            sort(x.second.begin(), x.second.end());
            for(auto y: x.second)
                ans.push_back(y);
        }
        return ans;
    }
};