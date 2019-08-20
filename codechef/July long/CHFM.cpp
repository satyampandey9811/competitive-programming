
#include <bits/stdc++.h>
#define eps 1e-6
using namespace std;

void testcase() {
	
	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long int sum = accumulate(a.begin(), a.end(), 0LL);			
	
	for (int i = 0; i < n; i++) {				
		//abs((1.0 * sum) / n - (1.0 * (sum - a[i])) / (n - 1)) < eps
		if (sum*(n-1)==(sum-a[i])*n) {
			cout << i+1;
			return;
		}
	}
	cout << "Impossible";
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