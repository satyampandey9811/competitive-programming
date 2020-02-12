// link to question - https://leetcode.com/problems/maximum-average-subarray-i/

class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        double ans=INT_MIN, current;
        int n=a.size(), sum=0;
        short int c=0;
        for(int i=0;i<n;i++){            
            sum+=a[i];            
            if(i+1==k){
                current=(double)sum/k;
                ans=max(ans,current);                                
            }
            else if(i+1>k){
                sum-=a[c];
                c++;
                current=(double)sum/k;
                ans=max(ans,current);
            }
        }                
        return ans;
    }
};