// link to question - https://leetcode.com/problems/counting-elements/

class Solution {
public:
    int countElements(vector<int>& a) {
        int ans = 0;
        unordered_map<int, int> m;
        
        for(auto i: a)
            m[i]++;
        
        for(auto i: m){            
            if(m.find(i.first + 1) != m.end())
                ans += i.second;
        }
        
        return ans;
    }
};