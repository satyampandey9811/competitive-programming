// link to question - https://leetcode.com/problems/minimum-number-of-frogs-croaking/

class Solution {
public:
    int minNumberOfFrogs(string s) {
        int n = s.size(), cnt = 0, ans = 0;
        
        if(n % 5 != 0) return -1;
        
        vector<vector<int>> a(5);
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'c') a[0].push_back(i);
            else if(s[i] == 'r') a[1].push_back(i);
            else if(s[i] == 'o') a[2].push_back(i);
            else if(s[i] == 'a') a[3].push_back(i);
            else a[4].push_back(i);
        }
        n /= 5;
        for(int i = 0; i < 5; i++)
            if(a[i].size() != n) return -1;
        
        for(int i = 1; i < 5; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] < a[i - 1][j])
                    return -1;
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'c') cnt++;
            else if(s[i] == 'k') cnt--;
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};