// link to question - https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/

class Solution {
public:
    vector<string> cellsInRange(string s) {
        int l = s[1] - '0';
        int h = s[4] - '0';
        vector<string> res;
        
        for (char ch = s[0]; ch <= s[3]; ch++) {
            for (int i = l; i <= h; i++) {
                res.push_back(ch + to_string(i));
            }
        }
        
        return res;
    }
};