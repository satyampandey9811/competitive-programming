// link to question - https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

class Solution {
public:
    vector<vector<int>> a;    
    int n;
    
    bool find(int mid) {
        for(int i = mid; i <= n; i++) {
            for(int j = 0; j < 5; j++) {
                if((a[j][i] - a[j][i-mid]) & 1) break;                
                if(j == 4) return 1;
            }
        }
        return 0;
    }
    
    int findTheLongestSubstring(string s) {         
        n = s.size();
        a.resize(5, vector<int>(n + 1));
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') a[0][i+1]++;
            else if(s[i] == 'e') a[1][i+1]++;
            else if(s[i] == 'i') a[2][i+1]++;
            else if(s[i] == 'o') a[3][i+1]++;
            else if(s[i] == 'u') a[4][i+1]++;
            a[0][i+1] += a[0][i];
            a[1][i+1] += a[1][i];
            a[2][i+1] += a[2][i];
            a[3][i+1] += a[3][i];
            a[4][i+1] += a[4][i];            
        }
        int ans = 0;
        for(int i = n; i >= 0; i--) {
            if(find(i)) {ans = i; break;}
        }    
        
        return ans;
    }
};