// link to question - https://www.hackerrank.com/challenges/correctness-invariant/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    for(int i=1;i<n;i++){
        int  temp=a[i],j=i-1;
        while(j>=0 and a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;    
    }
    for(auto x: a)
        cout<<x<<' ';
        
    return 0;
}
