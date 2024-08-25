# include<bits/stdc++.h>
# define ll long long

using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	ll ans = max(0, (n - k));
	for(int i=1; i<=n-k; i++){
		int h = k + i;
		ans += n - h;
		int q = n / h, r = n % h;
		ans += (q - 1) * i + max(0, (r - k + 1));
		// cout << n << " " << h << endl;
		// cout << h << ": " << n - h << " " << (q - 1) * i + max(0, (r - k + 1)) << endl;
	}
	cout << ans << endl;
}