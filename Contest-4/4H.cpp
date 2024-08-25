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
#include <complex>
#include <numeric>
#include <unordered_set>
#include <array>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define stp(n) fixed << setprecision(n)
#define scd(n) scanf("%d", &n);
#define sclld(n) scanf("%lld", &n);
#define sclld2(n, m) scanf("%lld %lld", &n, &m);
#define sclld3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c);
#define pii pair<int, int>
#define pdd pair<double, double>
#define ll long long
typedef array<int, 3> triple;
const ll mod = (ll)(1e9 + 7);
#define int long long
const ll inf = (ll)1e9;
//const ll inf = (ll)1e18;
#define A (ll)911382323
//#define A (ll)131
#define B (ll)972663749
//#define A (ll)3
//#define B (ll)97
const int N = 1e6;
const int M = 1000;
const int MAX = 1;

signed main() {
	int n, m, a, c, X;
	cin >> n >> m >> a >> c >> X;

	vector<int> x(n + 1);
	x[0] = X;
	for (int i = 1; i <= n; i++) {
		x[i] = (a * x[i - 1] + c) % m;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n;
		bool f = false;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (x[mid] == x[i]) {
				f = true;
				break;
			}
			else if (x[mid] < x[i]) {
				l = mid + 1;
			}
			else r = mid - 1;
		}
		if (f) cnt++;
	}

	cout << cnt << endl;

	return 0;
}