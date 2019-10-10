// link to question - https://www.hackerrank.com/challenges/strange-code/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {

    vector<long long> time(10000);
    for(int i=0;i<10000;i++)
        time[i]=3*pow(2,i);
    long long a=0,b,c;
    int i;
    for(i=0;i<10000;i++){
        a+=time[i];
        if(a>=t) break;
    }
    if(i==0){
        b=1;
        c=time[i];
    }
    else{
        b=a-time[i]+1;
        c=time[i];
    }
    while(b<t){
        c--;b++;
    }
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
