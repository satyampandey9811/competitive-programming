// link to question - https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& a) {
        int start = 0, end = a.size() - 1;
        
        for(int i = 0; i <= end;){
            if(a[i] == 0){
                a[i] = 1;
                a[start] = 0;
                start++;
                i++;
            }
            else if(a[i] == 2){
                swap(a[i], a[end]);
                end--;
            }
            else
                i++;
        }                
    }
};