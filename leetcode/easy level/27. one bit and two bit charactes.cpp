// link to question - https://leetcode.com/problems/1-bit-and-2-bit-characters/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& b) {
        int n=b.size();        
        bool a;
        for(int i=0;i<n;){
            if(b[i]){
                a=false;
                i+=2;
            }
            else{
                a=true;
                i++;
            }
        }
        return a;
    }
};