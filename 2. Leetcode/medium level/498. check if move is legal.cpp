// link to question - https://leetcode.com/problems/check-if-move-is-legal/

class Solution {
public:
    bool checkMove(vector<vector<char>>& a, int rm, int cm, char color) {
        int n = 8;
        
        if(rm - 1 >= 0) {
            int i = rm - 1;
            while(i >= 0 and a[i][cm] != color and a[i][cm] != '.') i--;
            if(i >= 0 and i < rm - 1 and a[i][cm] == color) return 1;
        }
        if(rm + 1 < n) {
            int i = rm + 1;
            while(i < n and a[i][cm] != color and a[i][cm] != '.') i++;
            if(i < n and i > rm + 1 and a[i][cm] == color) return 1;
        }
        if(cm - 1 >= 0) {
            int i = cm - 1;
            while(i >= 0 and a[rm][i] != color and a[rm][i] != '.') i--;
            if(i >= 0 and i < cm - 1 and a[rm][i] == color) return 1;
        }
        if(cm + 1 < n) {
            int i = cm + 1;
            while(i < n and a[rm][i] != color and a[rm][i] != '.') i++;
            if(i < n and i > cm + 1 and a[rm][i] == color) return 1;
        }
        
        if(rm - 1 >= 0 and cm - 1 >= 0) {
            int i = rm - 1, j = cm - 1;
            while(i >= 0 and j >= 0 and a[i][j] != color and a[i][j] != '.') i--, j--;
            if(i >= 0 and i < rm - 1 and j >= 0 and j < cm - 1 and a[i][j] == color) return 1;
        }
        
        if(rm - 1 >= 0 and cm + 1 < n) {
            int i = rm - 1, j = cm + 1;
            while(i >= 0 and j < n and a[i][j] != color and a[i][j] != '.') i--, j++;
            if(i >= 0 and i < rm - 1 and j < n and j > cm + 1 and a[i][j] == color) return 1;
        }
        
        if(rm + 1 >= 0 and cm - 1 >= 0) {
            int i = rm + 1, j = cm - 1;
            while(i < n and j >= 0 and a[i][j] != color and a[i][j] != '.') i++, j--;
            if(i < n and i > rm + 1 and j >= 0 and j < cm - 1 and a[i][j] == color) return 1;
        }

        if(rm + 1 >= 0 and cm + 1 < n) {
            int i = rm + 1, j = cm + 1;
            while(i < n and j < n and a[i][j] != color and a[i][j] != '.') i++, j++;
            if(i < n and i > rm + 1 and j < n and j > cm + 1 and a[i][j] == color) return 1;
        }
        return 0;
    }
};