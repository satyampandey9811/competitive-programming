// link to question - https://leetcode.com/problems/goat-latin/

class Solution {
public:                
    string toGoatLatin(string s) {
        int c = 1, n = s.size();
        string ans;
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for(int i = 0; i < n; i++) {
            int j = i;
            string t = "";
            if(st.count(s[j]) == 0) t += s[j], j++;
            while(j < n and s[j] != ' ') {
                ans += s[j++];
            }
            ans += t + "ma";
            for(int k = 0; k < c; k++) ans += 'a';            
            c++;
            i = j;
            ans += ' ';
        }
        
        ans.pop_back();
        return ans;
    }
};