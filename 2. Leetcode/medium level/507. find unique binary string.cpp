// link to question - https://leetcode.com/problems/find-unique-binary-string/

class Solution {
public:
    set<string> s;
    string ans;
    
    bool go(int i, int n, vector<string>& a, string l) {
        if(i == n) {
            if(s.count(l) < 1) {
                ans = l;
                return 1;
            }
            return 0;
        }
        
        if(go(i + 1, n, a, l + '0')) return 1;
        if(go(i + 1, n, a, l + '1')) return 1;
        return 0;
    } 
    
    string findDifferentBinaryString(vector<string>& a) {
        int n = a.size();
        for(auto &i :a) s.insert(i);
        string l;
        go(0, n, a, l);
        return ans;
    }
};