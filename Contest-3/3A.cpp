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
const int N = 1000 + 1;
const int M = 20;
const int MAX = 1;

int calc(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

signed main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> A(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i].first >> A[i].second;
	}

	vector<pair<int, int>> B(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> B[i].first >> B[i].second;
	}

	int f[N][N][2];
	memset(f, 0, sizeof f);
	f[0][0][1] = f[0][0][0] = f[1][0][1] = 0;
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j][0] = f[i][j][1] = INT_MAX;
		}
	}*/

	for (int i = 2; i <= n; i++) {
		f[i][0][1] = f[i - 1][0][1] + calc(A[i], A[i - 1]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == n && j <= m - 1) continue;

			int gt = i - 1 >= 1 ? calc(A[i - 1], A[i]) : INT_MAX;
			int gt2 = i - 1 >= 1 ? calc(A[i], B[j]) : INT_MAX;

			f[i][j][1] = min(gt + f[i - 1][j][1], gt2 + f[i - 1][j][0]);

			int gt3 = calc(B[j], A[i]);
			int gt4 = j - 1 >= 1 ? calc(B[j], B[j - 1]) : INT_MAX;
			f[i][j][0] = min(gt3 + f[i][j - 1][1], gt4 + f[i][j - 1][0]);
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << f[i][j][1] << ", " << f[i][j][0] << " | ";
		}
		cout << endl;
	}*/

	cout << f[n][m][1] << endl;

	return 0;
}