// link to question - https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int> e;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int i = 0, j = 0, n = a.size(), m = b.size();
        
        while(i < n and j < m){
            if(a[i] == b[j]){
                e.push_back(a[i]);
                int k = i + 1;
                while(k < n and a[k] == a[i]) k++;
                i = k;
                
                k = j + 1;
                while(k < m and b[k] == b[j]) k++;
                j = k;
            }
            else if(a[i] < b[j]) i++;
            else j++;
        }
        return e;
    }
};