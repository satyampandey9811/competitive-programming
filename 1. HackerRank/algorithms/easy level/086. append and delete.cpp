// link to question - https://www.hackerrank.com/challenges/append-and-delete/problem

# include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {

    int m=s.size(),n=t.size(),c=0;
    if(s==t)
        return "Yes";
    if(s[0]!=t[0]){
        if(k>=m+n)
            return "Yes";
        else
            return "No";
    }
    int i=0;
    while(s[i]==t[i]){
        c++;i++;
    }
    int z = m + n - (2 * c);
    if(k>=z){
        if(((m==1 or n==1)and s[0]!=t[0])and k>=m+n)
            return "Yes";
        else if ((m == 1 or n == 1) and s[0] == t[0]){
            if(k==z or k>=z+2)
                return "Yes";
            else
                return "No";
        }
        else if (z%2==0 and k%2==0) 
            return "Yes";
        else if(z%2!=0 and k%2!=0)
            return "Yes";
        else
            return "No";
    }
    else
        return "No";
    return " ";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
