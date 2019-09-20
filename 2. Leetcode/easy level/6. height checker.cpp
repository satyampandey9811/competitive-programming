// link to question - https://leetcode.com/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& h) {
        int n=h.size(),c=0,prev = -1;
        for(int i = 0; i < n; i++){
            if(h[i] < prev){
                c++;
            }
            else prev = h[i];
        }
        return c;
    }
};