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

struct Point {
	int x, y;
	void read() { cin >> x >> y; }
	Point operator +(const Point& b) const { return Point{ x + b.x, y + b.y }; }
	Point operator -(const Point& b) const { return Point{ x - b.x, y - b.y }; }
	int operator *(const Point& b) const { return x * b.y - y * b.x; }

	void operator -=(const Point& b) {
		x -= b.x;
		y -= b.y;
	}

	void operator +=(const Point& b) {
		x += b.x;
		y += b.y;
	}

	ll cross(Point& p1, Point& p2) {
		return (*this - p1) * (*this - p2);
	}

};
int n;
vector<Point> p;

int intersect(Point a, Point b, Point c, Point d) {
	if ((b - a) * (c - d) == 0) {
		if ((c - a) * (c - b) != 0) {
			return 0;
		}

		for (int rep = 0; rep < 2; rep++) {
			if (max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)) {
				return 0;
			}
			swap(a, c);
			swap(b, d);
		}
		return 1;
	}

	for (int rep = 0; rep < 2; rep++) {
		int cross1 = (c - a) * (c - b);
		int cross2 = (d - a) * (d - b);

		if ((cross1 < 0 && cross2 < 0) || (cross1 > 0 && cross2 > 0)) {
			return 0;
		}
		swap(a, c);
		swap(b, d);
	}

	return 2;
}


pdd calcIntersect(Point& a, Point& b, Point& c, Point& d) {

	int a1 = b.y - a.y;
	int b1 = a.x - b.x;
	int c1 = -(a1 * a.x + b1 * a.y);


	int a2 = d.y - c.y;
	int b2 = c.x - d.x;
	int c2 = -(a2 * c.x + b2 * c.y);



	int D = (a1 * b2 - b1 * a2);

	int dx = -c1 * b2 + c2 * b1;
	int dy = -c2 * a1 + c1 * a2;


	double x = dx * 1.0 / D;
	double y = dy * 1.0 / D;
	return { x, y };
}

double distance(pdd a, pdd b) {
	double x1 = a.first;
	double y1 = a.second;
	double x2 = b.first;
	double y2 = b.second;

	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double distance(Point a, Point b) {
	double x1 = a.x;
	double y1 = a.y;
	double x2 = b.x;
	double y2 = b.y;

	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double distance(Point a, pdd b) {
	double x1 = a.x;
	double y1 = a.y;
	double x2 = b.first;
	double y2 = b.second;

	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}


bool segment_contain(Point a, Point b, Point c) {
	if ((c - a) * (c - b) != 0) {
		return false;
	}
	return (min(a.x, b.x) <= c.x && max(a.x, b.x) >= c.x) &&
		(min(a.y, b.y) <= c.y && max(a.y, b.y) >= c.y);
}

int pointInPolygon(Point pt) {

	Point out = { pt.x + 1, 2000000010LL };

	bool bound = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int j = (i == n - 1 ? 0 : i + 1);
		if (segment_contain(p[i], p[j], pt)) {
			bound = true;
			break;
		}
		if (intersect(pt, out, p[i], p[j])) {
			cnt++;
		}
	}

	if (bound) return 0;
	else {
		if (cnt == 1) return 1;
		else return -1;
	}

	/*if (bound) cout << "BOUNDARY\n";
	else {
		if (cnt % 2 == 0) cout << "OUTSIDE\n";
		else cout << "INSIDE\n";
	}*/

}


signed main() {
	sclld(n);
	p.resize(n);

	for (int i = 0; i < n; i++) {
		p[i].read();
	}

	Point p1, p2;
	p1.read();
	p2.read();

	int cnt = 0;
	vector<Point> inter;

	map<pair<double, double>, int> mp;
	for (int i = 0; i < n; i++) {
		int j = (i == n - 1) ? 0 : i + 1;
		int t = intersect(p1, p2, p[i], p[j]);
		if (t == 2) {
			auto it = calcIntersect(p1, p2, p[i], p[j]);
			if (!mp[{it.first, it.second}])
				mp[{it.first, it.second}] = 1;
			else continue;

			cnt++;
			inter.push_back(p[i]);
			inter.push_back(p[j]);
		}
		else if (t == 1) {
			inter.clear();
			cnt = 1;
			inter.push_back(p[i]);
			inter.push_back(p[j]);
			break;
		}
	}
	double res = 0.0;
	if (cnt == 2) {
		res = distance(calcIntersect(p1, p2, inter[0], inter[1]), calcIntersect(p1, p2, inter[2], inter[3]));
	}

	if (cnt == 1) {
		if (intersect(p1, p2, inter[0], inter[1]) == 1) {
			auto a = p1;
			auto b = p2;
			auto c = inter[0];
			auto d = inter[1];

			//cout << "here\n";
			//cout << c.x << " " << c.y << " " << d.x << " " << d.y << endl;
			for (int rep = 0; rep < 2; rep++) {
				for (int rep2 = 0; rep2 < 2; rep2++) {
					if (segment_contain(a, b, c)) {

						if (segment_contain(a, b, d)) {
							//cout << 1 << endl;
							res = distance(c, d);
						}
						else {
							if (segment_contain(c, d, b)) {
								//cout << 2 << endl;
								res = distance(b, c);
							}
							else res = distance(a, c);
						}
					}
					if (res > 0) break;
					swap(c, d);
				}

				if (res > 0) break;
				swap(a, c);
				swap(b, d);
			}
		}
		else {
			for (int rep = 0; rep < 2; rep++) {
				int t = pointInPolygon(p1);

				if (t == 1) {
					res = distance(p1, calcIntersect(p1, p2, inter[0], inter[1]));
				}

				if (res > 0) break;

				swap(p1, p2);
			}
		}
	}
	else if (cnt == 0) {
		int t = pointInPolygon(p1);
		int t1 = pointInPolygon(p2);
		if (t == 1 && t1 == 1) {
			res = distance(p1, p2);
		}
	}
	res *= 100;
	int ans = (int)res;
	cout << ans << endl;

	return 0;
}