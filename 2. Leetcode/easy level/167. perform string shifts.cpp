// link to question - https://leetcode.com/problems/perform-string-shifts/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& a) {
        int dir, amt, n = s.size();
        
        for(int i = 0; i < a.size(); i++){
            dir = a[i][0];
            amt = a[i][1];
            if(amt == 0) continue;
            reverse(s.begin(), s.end());
            if(dir == 1){
                reverse(s.begin(), s.begin() + amt);
                reverse(s.begin() + amt, s.end());
            }
            else{
                reverse(s.begin(), s.begin() + n - amt);
                reverse(s.begin() + n - amt, s.end());
            }
        }
        return s;
    }
};