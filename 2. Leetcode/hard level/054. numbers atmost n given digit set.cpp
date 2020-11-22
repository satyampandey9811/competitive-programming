// link to question - https://leetcode.com/problems/numbers-at-most-n-given-digit-set/

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& dig, int n) {
        int s = dig.size(), ans = 0, m = n; 
        vector<int> a, b;
                
        while(m > 0) {
            b.push_back(m % 10);
            m /= 10;
        }        
        reverse(b.begin(), b.end());
                
        for(int i = 1; i < b.size(); i++) {
            ans += pow(s, i);
        }
        
        for(int i = 0; i < s; i++) {
            a.push_back(stoi(dig[i]));
        }
        sort(a.begin(), a.end());                
                
        for(int i = 0; i < b.size(); i++) {
            for(int j = 0; j < a.size(); j++) {
                if(a[j] < b[i]) ans += pow(s, b.size() - i - 1);                
                else if(a[j] == b[i]) {
                    if(i + 1 == b.size()) ans++; 
                    // if(j + 1 == a.size()) return ans;
                    break;
                }
                else return ans;
                if(j + 1 == a.size()) return ans;                
            }            
        }
        
        return ans;
    }
};