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
#define pii pair<int, int>
#define ll long long
typedef array<int, 3> triple;
const ll mod = (ll)1e9 + 7;
#define int long long
const int inf = 1000000000;
//const ll inf = (ll)1e18;
const int N = 100 + 1;
const int M = 20;
const double mul = 1;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1 , 1 };

signed main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		char c[N][N];
		vector<int> row[N];
		int nextRow[N][N];
		int prevRow[N][N];
		vector<int> col[N];
		int nextCol[N][N];
		int prevCol[N][N];
		bool visited[N][N][4];
		memset(visited, false, sizeof visited);
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);

		string tmp = "^v<>";
		int xs, ys, xe, ye;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c[i][j];
				if (tmp.find(c[i][j]) != string::npos) {
					row[i].push_back(j);
					col[j].push_back(i);
				}

				if (c[i][j] == 'S') {
					xs = i;
					ys = j;
					c[i][j] = '.';
				}

				if (c[i][j] == 'G') {
					xe = i;
					ye = j;
					c[i][j] = '.';
				}
			}
		}

		for (int i = 1; i <= m; i++) {
			c[0][i] = c[n + 1][i] = '#';
			nextRow[0][i] = 0;
			prevRow[n + 1][i] = n + 1;
		}

		for (int i = 1; i <= n; i++) {
			c[i][m + 1] = c[i][0] = '#';
			nextCol[i][m + 1] = m + 1;
			prevCol[i][0] = 0;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (c[i - 1][j] == '#' || tmp.find(c[i - 1][j]) != string::npos) {
					nextRow[i][j] = i - 1;
				}
				else {
					nextRow[i][j] = nextRow[i - 1][j];
				}

				if (c[i][j - 1] == '#' || tmp.find(c[i][j - 1]) != string::npos) {
					prevCol[i][j] = j - 1;
				}
				else {
					prevCol[i][j] = prevCol[i][j - 1];
				}
			}
		}

		for (int i = n; i >= 1; i--) {
			for (int j = m; j >= 1; j--) {
				if (c[i + 1][j] == '#' || tmp.find(c[i + 1][j]) != string::npos) {
					prevRow[i][j] = i + 1;
				}
				else {
					prevRow[i][j] = prevRow[i + 1][j];
				}

				if (c[i][j + 1] == '#' || tmp.find(c[i][j + 1]) != string::npos) {
					nextCol[i][j] = j + 1;
				}
				else {
					nextCol[i][j] = nextCol[i][j + 1];
				}
			}
		}

		auto inBound = [&](int x, int y) {
			if (x >= 1 && x <= n && y >= 1 && y <= m && c[x][y] == '.') return true;
			return false;
		};

		auto id = [&](int x, int y) {
			if (c[x][y] == '^') return 1;
			else if (c[x][y] == '>') return 2;
			else if (c[x][y] == 'v') return 3;
			else return 4;
		};

		auto check = [&](int x, int y, int cnt) {
			int rotate = cnt % 4;
			//UP
			int r = nextRow[x][y];
			if (tmp.find(c[r][y]) != string::npos) {
				int t = id(r, y);
				t += rotate;
				if (t > 4) t -= 4;
				if (t == 3) return false;
			}

			int pr = prevRow[x][y];
			if (tmp.find(c[pr][y]) != string::npos) {
				int t = id(pr, y);
				t += rotate;
				if (t > 4) t -= 4;
				if (t == 1) return false;
			}


			int nc = nextCol[x][y];
			if (tmp.find(c[x][nc]) != string::npos) {
				int t = id(x, nc);
				t += rotate;
				if (t > 4) t -= 4;
				if (t == 4) return false;
			}

			int pc = prevCol[x][y];
			if (tmp.find(c[x][pc]) != string::npos) {
				int t = id(x, pc);
				t += rotate;
				if (t > 4) t -= 4;
				if (t == 2) return false;
			}
			return true;
		};

		queue<pair<int, int>> q;
		q.push({ xs, ys });
		int cnt = 0;

		int res = -1;
		while (q.size()) {
			int sz = q.size();
			cnt++;

			while (sz--) {
				auto x = q.front().first;
				auto y = q.front().second;

				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (inBound(nx, ny)) {
						if (check(nx, ny, cnt) && !visited[nx][ny][cnt % 4]) {
							if (nx == xe && ny == ye) {
								res = cnt;
								break;
							}
							visited[nx][ny][cnt % 4] = true;
							q.push({ nx, ny });
						}
					}
				}

			}
			if (res != -1) break;
		}
		if (res != -1) {
			cout << res << endl;
		}
		else cout << "impossible\n";
	}
}