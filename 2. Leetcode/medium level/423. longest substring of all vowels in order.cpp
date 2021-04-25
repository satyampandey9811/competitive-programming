// link to question - 423. longest substring of all vowels in order.cpp

class Solution {
public:
    int longestBeautifulSubstring(string a) {
        int n = a.size(), ans = 0, c = 1;
        set<char> s;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] <= a[i+1]) {
                c++;
                s.insert(a[i]);
                s.insert(a[i+1]);
            }
            else {
                if(s.size() == 5) ans = max(ans, c);
                s.clear();
                c = 1;
            }
        }
        if(s.size() == 5) ans = max(ans, c);
        
        if(ans > 1) return ans;
        return 0;
    }
};