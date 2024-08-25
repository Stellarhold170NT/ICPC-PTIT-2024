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
const int N = 1e5 + 1;
const int M = 20;
const int MAX = 1;

struct Data {
	int type;
	int x, y, z;
	int r, h;
	int gt;
	int gth;

	Data(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
		gt = x;
		type = 1;
		gth = z;
	}

	Data(int r, int h) {
		this->r = r;
		this->h = h;
		type = 2;
		gt = r * 2;
		gth = h;
	}

};

int calc(int x, int r) {
	int res = ceil(2 * sqrt(r * r * 1.0 - x * x * 1.0 / 4));
	return res;
}


signed main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<Data> v;

		for (int i = 0; i < n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			v.push_back(Data(x, y, z));
			v.push_back(Data(y, x, z));
			v.push_back(Data(x, z, y));
			v.push_back(Data(z, x, y));
			v.push_back(Data(y, z, x));
			v.push_back(Data(z, y, x));
		}

		for (int i = 0; i < m; i++) {
			int r, h;
			cin >> r >> h;
			v.push_back(Data(r, h));
		}

		sort(v.begin(), v.end(), [](Data a, Data b) {
			return a.gt < b.gt;
			});

		int sz = v.size();

		int f[N] = { 0 };

		int res = 0;
		for (int i = 0; i < sz; i++) {
			f[i] = v[i].gth;
			for (int j = 0; j < i; j++) {
				if (v[i].type == 1) {
					if (v[j].type == 1 && v[j].gt < v[i].gt && v[j].y < v[i].y && f[i] < f[j] + v[i].gth) {
						f[i] = f[j] + v[i].gth;
					}
					else
						if (v[j].type == 2 && v[j].gt <= v[i].gt && v[j].gt <= v[i].y && f[i] < f[j] + v[i].gth) {
							f[i] = f[j] + v[i].gth;
						}
				}
				else if (v[i].type == 2) {
					if (v[j].type == 2 && v[j].gt <= v[i].gt && f[i] < f[j] + v[i].gth) {
						f[i] = f[j] + v[i].gth;
					}
					else if (v[j].type == 1 && v[j].gt < v[i].gt && v[j].y <= calc(v[j].gt, v[i].r) && f[i] < f[j] + v[i].gth) {
						f[i] = f[j] + v[i].gth;
					}
				}
			}
			res = max(res, f[i]);
		}

		cout << res << endl;
	}

	return 0;
}