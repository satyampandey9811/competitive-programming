// link to question - https://leetcode.com/problems/self-dividing-numbers/

class Solution {
public:
    vector<int> selfDividingNumbers(int l, int r) {
        vector<int> a;
        int f=1;
        for(int i=l;i<=r;i++){
            int n=i;
            while(n>0){
                int x=n%10;
                if(x==0 or (x!=0 and i%x!=0)){
                 f=0;   break;
                }
                n=n/10;                    
            }
            if(f)
                a.push_back(i);
            f=1;
        }
        return a;
    }
};