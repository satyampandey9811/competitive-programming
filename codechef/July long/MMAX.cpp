// link to question - https://www.codechef.com/JULY19B/problems/MMAX/

#include <bits/stdc++.h>

using namespace std;

long long int power(long long int x, int y, int p)
{
	long long int res = 1;    

	x = x % p;  				

	while (y > 0)
	{		
		if (y & 1)
			res = (res*x) % p; 
		y = y >> 1; 
		x = (x*x) % p;
	}
	return res;
}

void testcase() {

	int n;
	string k;
	cin >> n >> k;
	long long int ans = 0;
	reverse(k.begin(), k.end());
	for (int i = 0; i < k.size(); i++) {
		int d = k[i] - '0';
		ans = ans + (power(10, i,n)*d);
		ans = ans % n;
	}
	ans = ans % n;
	
	
	int x = ans, y = n - ans;
	
	vector<int> a;
	while (x > 0 and y > 0) {
		if (x > y) {
			a.push_back(1);
			a.push_back(0);
			x--; y--;
		}
		else {
			a.push_back(0);
			a.push_back(1);
			x--; y--;
		}
	}
	while (x > 0) {
		a.push_back(1);
		x--;
	}
	while (y > 0) {
		a.push_back(0);
		y--;
	}
	int sum = 0;
	for (int i = 0; i < a.size() - 1; i++) {
		sum += abs(a[i] - a[i + 1]);
	}
	cout << sum << endl;
}

int main() {
#ifdef SP
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout << "Case #" << i << ": ";
		testcase();
		cout << '\n';
	}
	return 0;
}