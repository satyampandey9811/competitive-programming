// link to question - https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        int n = s.size(), i, ans = 0;
        bool flag = false;
        
        for(i = n - 1; i >= 0; i--){
            if(!flag){
                ans += m[s[i]];
                if(i - 1 >= 0 and m[s[i - 1]] < m[s[i]]){
                    ans -= m[s[i - 1]];
                    flag = true;
                }
            }
            else{
                if(i - 1 >= 0 and m[s[i - 1]] < m[s[i]])
                    ans -= m[s[i - 1]];                    
                else
                    flag = false;
            }
        }
        return ans;
    }
};