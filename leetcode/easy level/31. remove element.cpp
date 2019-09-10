// link to question - https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int n=a.size(),c=0;
        
        for(int i=0,j=n-1;i<=j;){
            
            if(a[i]==val and a[j]!=val){
                swap(a[i],a[j]);
                c++;i++;j--;
            }           
            else if(a[i]==val)
                j--;
            else if(a[i]!=val){
                i++;c++;
            }
            
        }
        return c;
    }
};