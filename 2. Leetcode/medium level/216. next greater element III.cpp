// link to question - https://leetcode.com/problems/next-greater-element-iii/

class Solution {
public:
    int nextGreaterElement(int n) {
        string a = to_string(n);
        next_permutation(a.begin(), a.end());
        if(a > to_string(n) and stoll(a) < 2147483648) return stoll(a);
        return -1;
    }
};