#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define pi 3.1415926535897932384626
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << ' : ' << x << endl;
#define deb2(x, y) cout << #x << ' : ' << x << ', ' << #y << ' : ' << y << endl;
#define Yes cout << "Yes";
#define YES cout << "YES";
#define No cout << "No";
#define NO cout << "NO";

void testcase(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    map<int, char> m;
    for(int i = 0; i < n; i++) {
        m[i] = a[i];
    }
    while(1) {       
        bool f = false; 
        for(auto i = m.begin(); i != m.end(); i++) {
            int x = (*i).first;
            auto j = i;            
            j++;
            if(j == m.end()) {cout << "N"; return;}
            auto k = j;
            k++;
            if(k == m.end()) {cout << "N"; return;}
            vector<int> v(2);
            v[(*i).second - 'A']++;
            v[(*j).second - 'A']++;
            v[(*k).second - 'A']++;
            if(v[0] == 2) {
                f = true;                
                m.erase(i), m.erase(j), m.erase(k);                
                m[x] = 'A';
            }
            else if(v[1] == 2) {
                f = true;                
                m.erase(i), m.erase(j), m.erase(k);                
                m[x] = 'B';
            }
            if(f) break;
        }
        if(!f) {
            cout << "N";
            return;
        }
        if(m.size() == 1) {
            cout << "Y";
            return;
        }
    }
}

signed main() {
#ifdef SP
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(NULL);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";        
        testcase();        
        cout << endl;
    }
}