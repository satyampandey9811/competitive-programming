// link to question - https://www.hackerrank.com/challenges/flipping-bits/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {

    string a="00000000000000000000000000000000";
    if(n==1)
        a[31]='1';
    else if(n>1){
        int i=31;
        while(n>1){
            int x=n%2;
            if(x) a[i]='1';
            i--;
            n/=2;
        }
        a[i]='1';
    }
    for(int i=0;i<32;i++){
        if(a[i]=='0') a[i]='1';
        else a[i]='0';
    }
    long long ans=0;
    int x=0;
    for(int i=31;i>=0;i--){
        if(a[i]=='1')
            ans+=pow(2,x);
        x++;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
