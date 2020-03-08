// link to question - https://leetcode.com/problems/increasing-decreasing-string/

class Solution {
public:
    string sortString(string a) {
        string s;
        map<char, int> m;
        for(auto x: a) m[x]++;
        int n = a.size();
       T 
        while(s.size() != n){
            for(auto it = m.begin(); it != m.end(); it++){
                if(it -> second > 0){
                    s += it -> first;
                    it -> second--;
                }
            }                            
            for(auto it = m.rbegin(); it != m.rend(); it++){
                if(it -> second > 0){
                    s += it -> first;
                    it -> second--;
                }
            }            
        }
        return s;
    }
};