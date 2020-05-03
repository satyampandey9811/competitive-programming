// link to question - https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string a, string b) {
        vector<int> c(26);        
        for(auto x: a) c[x-'a']++;        
        for(auto x: b) c[x-'a']--;        
        for(auto x: c) {
            if(x > 0) return 0;                        
        }
        return 1;
    }
};
static auto x = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return nullptr;
}();