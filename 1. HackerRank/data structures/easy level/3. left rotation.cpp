// link to question - https://www.hackerrank.com/challenges/array-left-rotation/problem

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    reverse(a.begin(),a.end());
    reverse(a.begin(),a.begin()+n-d);
    reverse(a.begin()+n-d,a.end());
    for(auto x:a)cout<<x<<' ';
}
