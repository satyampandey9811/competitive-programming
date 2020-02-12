// link to question - https://www.hackerrank.com/challenges/kaprekar-numbers/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    int x=0;
    for (int i = p; i <= q; i++) {
        long long int a = 1LL*i*i;
        string b = to_string(a);
        
        int n = b.size();int e,f;
        
        if(n==1){
            e=0;
            string d=b.substr(n/2,n);
            f=stoi(d);
        }
        else {
            string c = b.substr(0, n / 2);
            string d = b.substr(n / 2, n );
            e = stoi(c);
            f = stoi(d);
        }
        
        if (e + f == i) {
          cout << i << ' ';
          x++;
        }
    }
    if(x==0)
    cout<<"INVALID RANGE";
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
