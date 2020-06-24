// link to question - https://leetcode.com/problems/guess-number-higher-or-lower/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long int i = 1,j = n, mid;
        while(i <= j){
            mid = (i + j) / 2;
            if(guess(mid) == 0)
                return mid;
            else if(guess(mid) == 1)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return 0;
    }
};