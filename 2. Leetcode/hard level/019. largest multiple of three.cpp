// link to question - https://leetcode.com/problems/largest-multiple-of-three/

class Solution {
public:
    string largestMultipleOfThree(vector<int>& nums) {
        string ans;
        vector<int> c(10);
        int sum = 0;
        for(int i: nums) sum += i, c[i]++;
        if(sum % 3 == 2) {
            if(sum % 3 == 2 and c[2]) c[2]--, sum -= 2;
            if(sum % 3 == 2 and c[5]) c[5]--, sum -= 5;
            if(sum % 3 == 2 and c[8]) c[8]--, sum -= 8;
            if(sum % 3 == 2) {
                int d = 0;
                while(d < 2) {
                    if(c[1]) c[1]--, sum -= 1;
                    else if(c[4]) c[4]--, sum -= 4;
                    else if(c[7]) c[7]--, sum -= 7;
                    d++;
                }
            }
        }
        else if(sum % 3 == 1) {
            if(sum % 3 == 1 and c[1]) c[1]--, sum -= 1;
            if(sum % 3 == 1 and c[4]) c[4]--, sum -= 4;
            if(sum % 3 == 1 and c[7]) c[7]--, sum -= 7;
            if(sum % 3 == 1) {
                int d = 0;
                while(d < 2) {
                    if(c[2]) c[2]--, sum -= 2;
                    else if(c[5]) c[5]--, sum -= 5;
                    else if(c[8]) c[8]--, sum -= 8;
                    d++;
                }
            }
        }
        if(sum == 0 and c[0]) return "0";
        if(sum == 0) return "";
        for(int i = 9; i >= 0; i--) {
            for(int j = 0; j < c[i]; j++) ans += '0' + i;
        }
        return ans;
    }
};