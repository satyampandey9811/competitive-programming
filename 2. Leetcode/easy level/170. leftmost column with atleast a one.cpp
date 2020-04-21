// link to question - https://leetcode.com/problems/leftmost-column-with-at-least-a-one/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {        
        vector<int> dim = binaryMatrix.dimensions();
        int m = dim[0], n = dim[1];
        int ans = 1000;        
        
        for(int i = 0; i < m; i++){
            int s = 0, e = n - 1, mid;
            
            while(s <= e){
                mid = s + (e - s) / 2;
                if(binaryMatrix.get(i, mid) == 1) {
                    ans = min(ans, mid);
                    e = mid - 1;
                }
                else s = mid + 1;
            }
        }
        if(ans == 1000) return -1;
        return ans;
    }
};