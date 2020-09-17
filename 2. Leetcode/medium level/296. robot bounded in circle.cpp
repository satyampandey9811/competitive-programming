// link to question - https://leetcode.com/problems/robot-bounded-in-circle/

class Solution {
public:
    bool isRobotBounded(string a) {
        int x = 0, y = 0, c = 0;
        int dir = 0;
        
        vector<char> direction = {'N', 'E', 'S', 'W'};
        
        for (int i = 0; i < a.size(); i++) {
            
            if (a[i] == 'G') {
                if (dir == 0) y++;
                else if (dir == 1) x++;
                else if (dir == 2) y--;
                else x--;
                c++;
            }
            
            else if (a[i] == 'L') {
                dir = (dir - 1 + 4) % 4;
            }
            
            else if (a[i] == 'R') {
                dir = (dir + 1) % 4;
            }
        }
        
        if (x == 0 and y == 0) return 1;
        return dir != 0;
    }
};