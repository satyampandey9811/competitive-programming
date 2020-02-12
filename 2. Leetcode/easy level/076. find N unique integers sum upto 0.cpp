// link to question - https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> a;
        if(n==1) return {0};
        if(n%2!=0){
           a.push_back(0); 
        }
        for(int i=1;i<=n/2;i++){
            a.push_back(i);
            a.push_back(i*(-1));
        }
        return a;
    }
};