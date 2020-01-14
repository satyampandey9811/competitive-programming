// link to question - https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {    
        int n=a.size();        
        if(k==0){
            int flag=0;
            for(int i=0;i<n-1;i++){
                if(a[i]==0 and a[i+1]==0){
                    flag=1;
                    break;
                }
            }
            if(flag) return true;
            else return false;
        }
        for(int i=0;i<n-1;i++){
            int sum=a[i];
            for(int j=i+1;j<n;j++){
                sum+=a[j];
                if(sum%k==0)
                    return true;
            }
        }
        return false;
    }
};