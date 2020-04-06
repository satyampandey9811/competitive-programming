// link to question - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        
        while(s.size() != 1){
            ans++;
            if(s[s.size() - 1] == '1'){
                for(int i = s.size() - 1; i >= 0; i--){
                    if(s[i] == '0'){
                        s[i] = '1';
                        break;
                    }
                    else s[i] = '0';                    
                }
                if(s[0] == '0') s = '1' + s;
            }
            else s.pop_back();            
        }
        
        return ans;
    }
};