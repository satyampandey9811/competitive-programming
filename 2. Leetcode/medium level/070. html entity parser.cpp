// link to question - https://leetcode.com/problems/html-entity-parser/

class Solution {
public:
    string entityParser(string a) {
        string ans;
        int n = a.size();
        
        for(int i = 0; i < n;){
            if(a[i] != '&'){
                ans += a[i];
                i++;
            }
            else{
                string s = a.substr(i + 1, 6);
                if(s == "frasl;"){
                    ans += '/';
                    i += 7;
                }
                else if(s[0] == 'l' and s[1] == 't' and s[2] == ';'){
                    ans += '<';
                    i += 4;
                }
                else if(s[0] == 'g' and s[1] == 't' and s[2] == ';'){
                    ans += '>';
                    i += 4;
                }
                else if(s[0] == 'a' and s[1] == 'm' and s[2] == 'p' and s[3] == ';'){
                    ans += '&';
                    i += 5;
                }
                else if(s[0] == 'a' and s[1] == 'p' and s[2] == 'o' and s[3] == 's' and s[4] == ';'){
                    ans += "'";
                    i += 6;
                }
                else if(s[0] == 'q' and s[1] == 'u' and s[2] == 'o' and s[3] == 't' and s[4] == ';'){
                    ans += '"';
                    i += 6;
                }
                else{
                    ans += '&';
                    i++;
                }
            }
        }
        return ans;
    }
};