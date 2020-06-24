// link to question - https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string a, string b) {
        string ans;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        
        while(i >= 0 or j >= 0 or carry) {
            int sum = 0;
            if(i >= 0) sum += a[i] - '0', i--;            
            if(j >= 0) sum += b[j] - '0', j--;
            sum += carry;
            carry = sum / 10;
            ans += to_string(sum % 10);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};