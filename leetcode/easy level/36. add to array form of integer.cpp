// link to question - https://leetcode.com/problems/add-to-array-form-of-integer/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& a, int k) {
        
        vector<int> c;
        int pos=a.size()-1;
        while(pos>-1 and k!=0){
            int x=a[pos]+k%10;
            c.push_back(x%10);
            pos--;
            k=(k/10)+(x/10);
        }
        while(pos>-1)
            c.push_back(a[pos--]);
        while(k!=0){
            c.push_back(k%10);
            k/=10;
        }
        reverse(c.begin(),c.end());
        return c;
    }
};