// link to question - https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& a) {
        int five = 0, ten = 0;
        for(int i = 0; i < (int)a.size(); i++) {
            if(a[i] == 5) five++;
            else if(a[i] == 10) {
                if(five) five--, ten++;                
                else return 0;
            }
            else {
                if(five and ten) five--, ten--;
                else if(five > 2) five -= 3;
                else return 0;
            }
        }
        return 1;
    }
};