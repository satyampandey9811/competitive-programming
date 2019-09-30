// link to question - https://www.hackerrank.com/challenges/strong-password/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string p) {
    // Return the minimum number of characters to make the password strong
    
    set<char> a={'!','@','#','$','%','^','&','*','(',')','-','+'};
    
    int s=0,l=0,u=0,d=0;char z;
    for(int i=0;i<n;i++){
        z=p[i];
        if(z>='A' and z<='Z')
            u=1;
        else if(z>='a' and z<='z')
            l=1;
        else if(z>='0' and z<='9')
            d=1;
        else if(a.find(z)!=a.end())
            s=1;
    }
    int x= 4-u-l-d-s;
    if(n>5)
        return x;
    if(x+n>5)
        return x;
    return 6-n;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
