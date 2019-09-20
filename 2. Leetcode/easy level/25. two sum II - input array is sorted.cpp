// link to question - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    int bsearch(vector<int> a,int i,int t){
    
        int p=i+1,q=a.size()-1;
        while(p<=q){
            int mid=(p+q)/2;
            if(a[i]+a[mid]==t)
                return mid;
            else if(a[i]+a[mid]<t)
                p=mid+1;
            else
                q=mid-1;
        }            
        return -1;
    }
    
    vector<int> twoSum(vector<int>& a, int t) {
        int p;
        for(int i=0;i<a.size()-1;i++){
            if(i>0 and a[i]==a[i-1])
                continue;
            p=bsearch(a,i,t);
            if(p==-1)
                continue;
            else
                return {i+1,p+1};
        }
        return {};
    }
};