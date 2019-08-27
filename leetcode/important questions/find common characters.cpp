// link to question - https://leetcode.com/problems/find-common-characters/submissions/

class Solution {
public:       
    vector<string> commonChars(vector<string>& a) {
        vector<string> f;
        int m=a.size(),n=a[0].size();        
        for(int i=0;i<n;i++){
            int c=1;
            for(int j=1;j<m;j++){                
                auto it=find(a[j].begin(),a[j].end(),a[0][i]);
                if(it!=a[j].end()){
                    *it='1';
                    c++;
                }
                else                    
                    break;                                    
            }     
            if(c==m){
                string str(1,a[0][i]);
                f.push_back(str);
            }
        }
        return f;
    }
};