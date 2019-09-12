// link to question - https://leetcode.com/problems/valid-mountain-array/

class Solution {
public:
    bool validMountainArray(vector<int>& a) {                
        
        int x=max_element(a.begin(),a.end())-a.begin();
        
        if(x==0 or x==a.size()-1)
            return false;
        
        for(int i=0;i<a.size()-1;i++){
            if(i<x){
                if(a[i]>=a[i+1])
                    return false;
            }        
            else {        
                if(a[i]<=a[i+1])
                    return false;
            }
        }
        return true;
    }
};