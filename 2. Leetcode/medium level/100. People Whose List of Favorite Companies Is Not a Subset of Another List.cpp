// link to question - https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/

class Solution {
public:
    
    bool present(const vector<string>& a,const vector<string>& b){
        int n = a.size(), m = b.size();
        if(n > m) return 0;
        int i = 0, j = 0;
        while(i < n and j < m){
            if(a[i] == b[j]) i++, j++;
            else j++;
        }
        return i == n;
    }
    
    vector<int> peopleIndexes(vector<vector<string>>& comp) {
        
        int n = comp.size();
        
        for(int i = 0; i < n; i++){
            sort(comp[i].begin(), comp[i].end());
        }
        vector<int> output;
        
        
        for(int i = 0; i < n; i++){
            bool f = 1;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                
                if(present(comp[i], comp[j])){
                    f = 0;
                    break;
                }
            }
            if(f) output.push_back(i);
        }
        return output;
    }
};