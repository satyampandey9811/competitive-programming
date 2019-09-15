// link to question - https://leetcode.com/problems/distribute-candies-to-people/

class Solution {
public:
    vector<int> distributeCandies(int ca, int n) {
        vector<int> a(n);
        
        int c=1;
        for(int i=0;ca>0;){
            if(c<=ca){
                a[i%n]+=c;ca-=c;
                c++;i++;
            }
            else if(c>ca){
                a[i%n]+=ca;ca=0;
                i++;
            }            
        }
        return a;
    }
};