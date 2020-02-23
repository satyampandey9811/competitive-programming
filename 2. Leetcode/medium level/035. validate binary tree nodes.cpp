// link to question - https://leetcode.com/problems/validate-binary-tree-nodes/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
        set<int> s;
        s.insert(0);
        for(int i = 0; i < n; i++){
            if(lc[i] != -1){
                if(s.find(lc[i]) == s.end())
                    s.insert(lc[i]);
                else 
                    return false;
            }
            if(rc[i] != -1){
                if(s.find(rc[i]) == s.end())
                    s.insert(rc[i]);
                else 
                    return false;
            }
        }
        if(s.size() == n)
            return true;
        return false;
    }
};