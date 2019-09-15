// link to question - https://www.hackerrank.com/challenges/counter-game/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the counterGame function below.
string counterGame(long n) {
    if(n==1)
        return "Richard";
    vector<long long> a;
    for(int i=1;i<=63;i++){
        a.push_back(pow(2,i));
    } 
    int x=0;
    while(n!=1){
        auto it=find(a.begin(),a.end(),n);
        if(it!=a.end()){
            n/=2;        
        }
        else{
            int i=0;
            while(a[i]<n)
                i++;
            n=n-a[i-1];
        }
        if(n==1) break;
        if(x==0) x=1;
        else x=0;
    }
    return (x==0)?"Louise" :"Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
