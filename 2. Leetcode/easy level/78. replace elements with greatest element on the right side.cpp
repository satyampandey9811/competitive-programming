// link to question - https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        int n=a.size();
        int maxv=INT_MIN, prev=a[n-1], stval=-1;
        for(int i=n-2;i>=0;i--){
            maxv=max(maxv,prev);
            prev=a[i];
            a[i+1]=stval;
            stval=maxv;
        }
        a[0]=stval;
        return a;
    }
};