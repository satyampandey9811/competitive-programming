// link to question - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        int ans = 0, mask = 0;
        
        for(int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            
            set<int> s;
            for(int num: a) {
                s.insert(num & mask);
            }
            
            int temp = ans | (1 << i);
            
            for(int num: s) {
                if(s.count(num ^ temp)) {
                    ans = temp;
                    break;
                }
            }
        }
        
        return ans;
    }
};