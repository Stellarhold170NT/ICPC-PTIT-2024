#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
#include <array>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define scd(n) scanf("%d", &n);
#define sclld(n) scanf("%lld", &n);
#define sclld2(n, m) scanf("%lld %lld", &n, &m);
#define sclld3(n, m, k) scanf("%lld %lld %lld", &n, &m, &k);
#define pii pair<int, int>
#define ll long long
typedef array<int, 3> triple;
ll mod = (ll)1e9 + 7;
const int inf = 1000000000;
#define int long long
//const ll inf = (ll)1e18;
const int N = 1e6 + 1;
const int M = 20;
const int MAX = 1;

int n;
int gt[N];

int gcd(int a, int b) {
	if (b == 0) return a;
	else return (b, a % b);
}

int pow(int a, int n, int md = mod) {
	if (n == 0) return 1;
	if (n == 1) return a;

	int tmp = pow(a, n / 2);
	if (n & 1) return ((tmp * tmp) % mod * a) % md;
	else return (tmp * tmp) % md;
}

void init() {
	gt[0] = gt[1] = 1;
	for (int i = 2; i <= n; i++) {
		gt[i] = (gt[i - 1] * i) % mod;
	}

}

int c(int k, int n) {
	ll ans = gt[n];
	ans = (ans * pow(gt[k], mod - 2)) % mod;
	ans = (ans * pow(gt[n - k], mod - 2)) % mod;
	return ans;
}

int gcdd(int a, int b) {
	if (b == 0) return a;
	return gcdd(b, a % b);
}

struct Matrix {
	int a, b, c, d;
};

Matrix I = { 1, 0, 1, 0 };

Matrix mul(Matrix a, Matrix b) {
	Matrix f;
	f.a = (a.a * b.a + a.b * b.c) % mod;
	f.b = (a.a * b.b + a.b * b.d) % mod;
	f.c = (a.c * b.a + a.d * b.b) % mod;
	f.d = (a.c * b.b + a.d * b.d) % mod;
	return f;
}

Matrix powMatrix(Matrix X, int n) {
	if (n == 0) return I;
	if (n == 1) return X;

	Matrix tmp = powMatrix(X, n / 2);
	if (n % 2 == 0) return mul(tmp, tmp);
	else return mul(X, mul(tmp, tmp));
}



signed main() {
	int t;
	cin >> t;

	while (t--) {
		int a, b, m;
		sclld3(a, b, m);

		mod = m;

		Matrix X = { 0, 1, 1, 1 };
		/*Matrix bm = powMatrix(X, b);
		Matrix am = powMatrix(X, a);*/
		Matrix f = powMatrix(X, gcdd(a, b));
		cout << f.b << endl;
	}

	return 0;
}
