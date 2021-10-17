// link to question - https://leetcode.com/problems/remove-colored-pieces-if-their-neighbors-are-the-same-color/

class Solution {
public:
    bool winnerOfGame(string a) {
        int al = 0, bo = 0;
        int n = a.size();
        
        for(int i = 0; i < n - 2; i++) {
            if(a[i] == 'A' and a[i+1] == 'A' and a[i+2] == 'A') al++;
            if(a[i] == 'B' and a[i+1] == 'B' and a[i+2] == 'B') bo++;
        }
        
        if(al > bo) return 1;
        return 0;
    }
};