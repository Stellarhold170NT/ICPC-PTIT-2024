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
//const int inf = 1000000000;
#define int long long
const ll inf = (ll)1e18;
const int N = 10000 + 1;
const int logN = 18;
const int M = 20;
const int MAX = 1;

signed main() {
	int n, k;
	cin >> n >> k;

	vector<double> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	double s = 0;

	if (k == 1) {
		sort(d.begin(), d.end());
		int median = d[n / 2];
		for (auto x : d) {
			s += abs(x - median);
		}
	}
	else {
		double mean = 0;
		for (auto x : d) {
			mean += x;
		}
		mean /= n;
		for (auto x : d) {
			s += (mean - x) * (mean - x);
		}
	}

	cout << fixed << setprecision(2) << s << endl;

	return 0;
}