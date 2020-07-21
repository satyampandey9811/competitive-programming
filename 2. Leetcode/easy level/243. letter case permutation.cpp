// link to question - https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size(), c = 0;
        vector<string> ans;
        vector<int> a;
        
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a' and s[i] <= 'z'){
                c++;                
                a.push_back(i);
            }
            else if(s[i] >= 'A' and s[i] <= 'Z'){
                c++;
                a.push_back(i);
                s[i] = s[i] + 32;
            }
        }
        
        for(int i = 0; i < (1 << c); i++){
            string temp = s;
            for(int j = 0; j < c; j++){
                if(i & (1 << j)){
                    temp[a[j]] = temp[a[j]] - 32;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};