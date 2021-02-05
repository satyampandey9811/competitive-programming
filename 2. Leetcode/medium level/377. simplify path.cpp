// link to question - https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string a) {
        deque<string> d;
        int j, n = a.size();
        
        for(int i = 0; i < n; i++) {
            if(a[i] == '/') continue;
            j = i;
            string b;
            while(j < n and a[j] != '/') {
                b += a[j];
                j++;
            }
            if(b.size() == 1 and b[0] == '.') continue;
            if(b.size() == 2 and b == "..") {
                if(d.size()) d.pop_back();
                i++;
            }
            else {
                d.push_back(b);
                i = j - 1;
            }
        }
        
        string ans;
        for(auto& i: d) {
            ans += "/";
            ans += i;            
        }
        
        if(ans.size() == 0) ans += "/";
        
        return ans;
    }
};