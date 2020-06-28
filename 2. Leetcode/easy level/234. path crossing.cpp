// link to question - https://leetcode.com/problems/path-crossing/

class Solution {
public:
    bool isPathCrossing(string a) {
        map<pair<int, int>, int> m;
        int x = 0, y = 0;
        m[{0, 0}] = 1;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == 'N') y++;
            else if(a[i] == 'S') y--;
            else if(a[i] == 'E') x++;
            else x--;
            if(m.count({x, y}) > 0) return 1;
            m[{x, y}] = 1;
        }
        return 0;
    }
};