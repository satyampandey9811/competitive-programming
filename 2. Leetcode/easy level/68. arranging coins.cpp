// link to question - https://leetcode.com/problems/arranging-coins/

class Solution {
public:
    int arrangeCoins(int n) {
        int c=0;
        int i=1;
        while(n>c){
            c++;
            n=n-c;
            
        }
        return c;
    }
};