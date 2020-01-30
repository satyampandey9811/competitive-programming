// link to question - https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string j, string s) {
        int ans = 0;
        sort(j.begin(),j.end());
        for(auto c: s){
            if(binary_search(j.begin(),j.end(),c))
                ans++;
        }
        return ans;
    }
};