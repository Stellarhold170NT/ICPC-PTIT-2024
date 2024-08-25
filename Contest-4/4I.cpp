# include<bits/stdc++.h>
# define ll long long


using namespace std;

void Solve(int a, int b, int add, int sub){
	if(a < b) swap(a, b); // a >= b
	else if(a == b && sub != add){
		cout << "NO\n";
		return;
	}
	else if(sub == add){
		cout << "YES\n";
		return;
	}
	int min_sign = min(add, sub), max_sign = max(add, sub);
	// if(a * min_sign < b * max_sign){
	// 	cout << "NO\n";
	// 	return;
	// }
	ll d = max_sign - min_sign;
	ll s = (ll)b * d;
	double ans = s * 1.0 / (a - b);
	if(ans == (ll)ans && ans <= min_sign) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int n; cin >> n;
	string s; cin >> s;
	int add = count(s.begin(), s.end(), '+');
	int sub = n - add;
	int q; cin >> q;
	while(q --){
		int a, b; cin >> a >> b;
		Solve(a, b, add, sub);
	}
}