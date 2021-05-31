// link to question - https://leetcode.com/problems/search-suggestions-system/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& a, string w) {
        int m = a.size(), n = w.size(), i = 0, j = 0;
        vector<vector<string>> ans(n);
        sort(a.begin(), a.end());
        
        string c;
        while(j < n) {
            c += w[j];
            vector<string> temp;
            int t = -1;
            while(i < m) {
                if(a[i].substr(0, j+1) == c) {
                    temp.push_back(a[i]);
                    if(t == -1) t = i;
                }
                if(temp.size() == 3) break;
                i++;
            }
            if(!temp.size()) return ans;
            ans[j] = temp;
            j++;
            i = t;
        }
        
        return ans;
    }
};