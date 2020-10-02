// link to question - https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:    
    vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    int n;
    
    void go(int i, string temp, string& a) {
        if(i == n) ans.push_back(temp);        
        else {            
            string t = m[a[i] - '0'];            
            for(int j = 0; j < t.size(); j++) {                
                go(i + 1, temp + t[j], a);                
            }            
        }
    }
    
    vector<string> letterCombinations(string a) {
        n = a.size(); 
        if(!n) return {};                                    
        string temp;
        go(0, temp, a);
        return ans;
    }
};