// link to question - https://leetcode.com/problems/multiply-strings/

class Solution {
public:
    vector<int> ans;
    
    void go(string &a, string &b) {
        int m = a.size(), n = b.size(), k = 0, pos = 0; 
        int carry = 0, digitA, digitB, mul;
        
        for(int i = n - 1; i >= 0; i--) {
            carry = 0;
            digitB = b[i] - '0';
            pos = k;
            
            if(n == 1 and digitB == 0) {
                ans[0] = 0;
                return;
            }
            
            for(int j = m - 1; j >= 0; j--) {
                digitA = a[j] - '0';
                
                mul = digitA * digitB + carry;
                if(ans[pos] == -1) ans[pos] = mul % 10;
                else ans[pos] += mul % 10;
                carry = mul / 10;
                
                pos++;
            }
            
            if(carry) ans[pos] = carry;
            k++;
        }
    }
    
    string multiply(string a, string b) {
        int m = a.size(), n = b.size();
        ans = vector<int>(500, -1);
        
        if(m >= n) go(a, b);
        else go(b, a);
        
        string res;
        
        int carry = 0, val, i;
        
        for(i = 0; ans[i] != -1 or carry; i++) {
            val = ans[i];
            if(val == -1) ans[i] = carry;
            else ans[i] += carry;
            
            carry = ans[i] / 10;
            ans[i] %= 10;
        }
        i--;
        while(i >= 0) {
            res += to_string(ans[i]);
            i--;
        }
        
        return res;
    }
};