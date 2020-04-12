// link to question - https://leetcode.com/problems/string-matching-in-an-array/

class Solution {
public:
    vector<string> stringMatching(vector<string>& a) {
        int n = a.size();
        vector<string> ans;
        
        for(int i = 0; i < n; i++){            
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(a[j].find(a[i]) != string::npos){
                    ans.push_back(a[i]);
                    break;
                }
            }
        }
        return ans;
    }
};