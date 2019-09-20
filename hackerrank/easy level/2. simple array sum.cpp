// link to question - https://www.hackerrank.com/challenges/simple-array-sum/problem

#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	int n,val,sum=0;
    cin>>n;
    
    for(int i=0;i<n;i++) {
        cin>>val;
        sum+=val;
    }
    
    cout<<sum;
	return 0;
}