// link to question - https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    int findNumbers(vector<int>& a) {
        int ans=0;
        for(int i=0;i<a.size();i++){
            int c=0;
            int num=a[i];
            while(num>0){
                c++;
                num/=10;
            }
            if(c%2==0) ans++;
        }
        return ans;
    }
};