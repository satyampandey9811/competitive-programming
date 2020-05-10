// link to question - https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {        
        vector<bool> trusts(n + 1, false);
        vector<int> trusted(n + 1);        
        
        for(vector<int>& v:trust) {            
            trusts[v[0]] = true;
            trusted[v[1]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(trusts[i] == false and trusted[i] == n - 1)
                return i;
        }
        return -1;
    }
};