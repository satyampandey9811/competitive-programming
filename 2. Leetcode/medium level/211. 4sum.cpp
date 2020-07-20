// link to question - https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int t) {        
        vector<vector<int>> ans;                
        int n = a.size(), sum, req;
        sort(a.begin(), a.end());
        map<vector<int>, int> m;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                req = t - a[i] - a[j];
                int k = j + 1, l = n - 1;
                while(k < l) {
                    sum = a[k] + a[l];
                    if(sum == req) {
                        vector<int> v = {a[i], a[j], a[k], a[l]};
                        if(m[v] == 0) ans.push_back(v), m[v]++;
                        k++;
                    }
                    else if(sum > req) l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};