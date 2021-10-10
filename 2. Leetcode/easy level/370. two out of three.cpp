// link to question - https://leetcode.com/problems/two-out-of-three/

class Solution {
public:
    set<int> s;
    
    void go(vector<int>& a, vector<int>& b) {
        int as = a.size(), bs = b.size();
        for(int i = 0; i < as; i++) {
            for(int j = 0; j < bs; j++) {
                if(a[i] == b[j]) {
                    s.insert(a[i]);
                    break;
                }
            }
        }
    }
    
    vector<int> twoOutOfThree(vector<int>& a, vector<int>& b, vector<int>& c) {
        vector<int> ans;
        
        go(a, b);
        go(a, c);
        go(b, c);
        
        for(auto &i :s) ans.push_back(i);
        
        return ans;
    }
};