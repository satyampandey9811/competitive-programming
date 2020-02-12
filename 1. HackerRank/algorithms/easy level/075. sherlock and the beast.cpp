// link to question - https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the decentNumber function below.
void decentNumber(int n) {
    int flag=0;
    int n3,n5;
    for(n3=0,n5=n;n3<=n;n3++,n5--){
        if(n3%5==0 and n5%3==0){
            flag=1;
            break;
        }
    }
    if(!flag){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<n5;i++) cout<<5;
    for(int i=0;i<n3;i++) cout<<3;
    cout<<endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        decentNumber(n);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
