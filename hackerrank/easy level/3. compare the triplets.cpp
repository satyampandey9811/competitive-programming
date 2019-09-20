// link to question - https://www.hackerrank.com/challenges/compare-the-triplets/problem

#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
    int p=0,q=0;
    int a[3],b[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    for(int i=0;i<3;i++){
        cin>>b[i];
    }
    for(int i=0;i<3;i++){
        if(a[i]>b[i])
         p+=1;
        else if(b[i]>a[i])
         q+=1;
            
    }
    cout<<p<<' '<<q;
	return 0;
}