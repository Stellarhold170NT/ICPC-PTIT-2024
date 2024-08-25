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


signed main() {
	int n;
	sclld(n);

	unordered_map<string, int> mcnt;
	unordered_map<string, int> mp;

	for (int i = 0; i < n; i++) {
		vector<int> v(5);
		for (int j = 0; j < 5; j++) sclld(v[j]);
		sort(v.begin(), v.end());

		for (int s = 1; s < 32; s++) {
			string h = "";
			int cnt = 0;
			for (int k = 0; k < 5; k++) {
				if (s & (1 << k)) {
					h = h + to_string(v[k]) + ",";
					cnt++;
				}
			}
			mp[h]++;
			mcnt[h] = cnt;
		}
	}

	int res = 0;

	for (auto x : mp) {
		string h = x.first;
		int cnth = x.second;
		if (cnth == 1) continue;
		int r = cnth * (cnth - 1) / 2;
		if (mcnt[h] % 2 == 0) res -= r;
		else res += r;
	}

	res = n * (n - 1) / 2 - res;
	printf("%lld\n", res);

	return 0;
}