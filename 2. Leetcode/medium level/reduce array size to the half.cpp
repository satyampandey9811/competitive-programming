// link to question - https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& a) {
        vector<pair<int, int>> s;
        unordered_map<int, int> m;
        int n = a.size();
        for(int i = 0; i < n; i++)
            m[a[i]]++;
        for(auto x: m){
            s.push_back({x.second, x.first});
        }
        int ans = 0, sum = 0;
        sort(s.begin(), s.end(), greater<>());
        for(int i = 0; i < s.size(); i++){
            sum += s[i].first;
            ans++;
            if(sum >= n/2)
                return ans;
        }
        return ans;
    }
};