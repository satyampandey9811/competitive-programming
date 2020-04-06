// link to question - https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    
    
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;        
        
        for(int i = 0; i < a.size(); i++){            
            vector<int> count(26);                        
            string temp;
            for(int j = 0; j < a[i].size(); j++)
                count[a[i][j] - 'a']++;
            
            for(int j = 0; j < 26; j++){
                if(count[j] != 0)
                    temp += count[j] * ('a' + j); 
            }
            m[temp].push_back(a[i]);
        }                
        
        for(auto x: m)           
            ans.push_back(x.second);        
        
        return ans;
    }
};