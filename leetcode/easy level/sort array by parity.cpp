// link to question - https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
 
      int i=0,j=a.size()-1;
        while(i<j){
            if(a[i]%2!=0 and a[j]%2==0)
                swap(a[i],a[j]);
            else if(a[i]%2==0)
                i++;
            else if(a[j]%2!=0)
                j--;
        }
        return a;
    }
};