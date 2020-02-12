// link to question - https://leetcode.com/problems/number-of-digit-one/

class Solution {
public:
    int countDigitOne(int num) {
        if(num < 0) return 0;
        int ans = 0, c1 = 0, c2, rem, val;
        string n = to_string(num);
        for(int i = n.size() - 1; i >= 0; i--){
            c1++;
            val = rem = n[i] - '0';
            if(rem == 0) continue;  
            if(c1 == 1){
                ans += 1; continue;
            }
            rem = rem * pow(10, c1 - 1);
            c2 = 1;
            while(c2 < c1){                        
                ans += rem / 10;                
                c2++;
            }        
            if(val == 1)
                ans += stoi(n.substr(n.size() + 1 - c1)) + 1;           
            else
                ans += pow(10, c2 - 1);            
        }
        return ans;
    }
};