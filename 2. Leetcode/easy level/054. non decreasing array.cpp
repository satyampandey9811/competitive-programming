// link to question - https://leetcode.com/problems/non-decreasing-array/

class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        
        int c=0;
        for(int i=0;i<a.size()-1;i++){            
            if(c==0 and a[i]>a[i+1]) {
                c++;
                if(i){
                if(a[i-1]<=a[i+1])
                    a[i]=a[i+1];
                else 
                    a[i+1]=a[i];
                }
            }
            else if(c>0 and a[i]>a[i+1])
                return false;
        }
        return true;
    }
};