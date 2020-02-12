// link to question - https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n=a.size();
        if(n==1)
            return a[0];
        int c=1;
        sort(a.begin(),a.end());
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                c++;
                if(c>n/2)
                    return a[i];
            }
            else 
                c=1;
        }
        return 0;
    }
};