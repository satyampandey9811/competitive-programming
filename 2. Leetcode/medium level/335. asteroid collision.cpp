// link to question - https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> ans;
        int n = a.size();        
        
        for(int i = 0; i < n; i++) {            
            if(a[i] > 0) ans.push_back(a[i]);
            else {
                bool f = true;
                while(ans.size() and ans.back() > 0) {                    
                    if(ans.back() >= abs(a[i])) {
                        f = false;
                        if(ans.back() == abs(a[i])) ans.pop_back();
                        break;
                    }
                    else ans.pop_back();       
                }
                if(f) ans.push_back(a[i]);
            }
        }
        
        return ans;
    }
};