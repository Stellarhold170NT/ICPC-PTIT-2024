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
const int N = 1010;
const int M = 100;
const int MAX = 1;

int n, m;
int dx[] = { -1, -1, -1, 0 , 0, 1, 1, 1 };
int dy[] = { 0, -1, 1, -1, 1, -1 , 0, 1 };
int dist[N][N];
bool visited[N][N];
char c[N][N];

struct Data {
	int x, y, d;

	bool operator < (const Data& b) const {
		return this->d > b.d;
	}
};

void init() {
	memset(visited, false, sizeof visited);
	for (int i = 2; i <= n - 1; i++) dist[i][0] = 0;
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; j <= m + 1; j++) {
			dist[i][j] = inf;
		}
	}
}

bool inBound(int x, int y) {
	if (x >= 2 && x <= n - 1 && y >= 0 && y <= m + 1) return true;
	return false;
}

void dfs(int x, int y, int val) {
	dist[x][y] = val;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inBound(nx, ny) && c[nx][ny] == '#' && dist[nx][ny] != val) {
			dfs(nx, ny, val);
		}
	}
}

signed main() {


	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}

	init();

	priority_queue<Data> p;

	for (int i = 2; i <= n - 1; i++) {
		c[i][0] = c[i][m + 1] = '#';
		dist[i][0] = 0;
	}

	p.push({ 2, 0, 0 });

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m + 1; j++) {
			cout << c[i][j];
		}
		cout << endl;
	}*/


	while (p.size()) {
		auto x = p.top().x;
		auto y = p.top().y;
		p.pop();

		if (visited[x][y]) continue;
		visited[x][y] = true;

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (inBound(nx, ny) && !visited[nx][ny]) {
				if (c[nx][ny] == '#' && dist[nx][ny] > dist[x][y]) {
					dfs(nx, ny, dist[x][y]);
				}
				else dist[nx][ny] = min(dist[x][y] + 1, dist[nx][ny]);
				p.push({ nx, ny, dist[nx][ny] });
			}
		}
	}

	int ans = inf;
	for (int i = 2; i <= n - 1; i++) ans = min(ans, dist[i][m + 1]);
	cout << ans << endl;

	return 0;
}