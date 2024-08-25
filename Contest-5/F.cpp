#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
struct P {
    double x, y;
};
double dist(P a, P b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
P circum(P a, P b, P c) {
    double D = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    double x = ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) * (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y)) / D;
    double y = ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) * (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x)) / D;
    return { x, y };
}
bool check(int n, int k, vector<P>& pts) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                P a = pts[i], b = pts[j], c = pts[l];
                P o = circum(a, b, c);
                double r = dist(o, a);
                int cnt = 0;
                for (int m = 0; m < n; m++) {
                    if (m == i || m == j || m == l) continue;
                    double d = dist(o, pts[m]);
                    if (d < r - EPS) cnt++;
                }

                if (cnt == k) return true;
            }
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<P> pts(n);
        for (int i = 0; i < n; i++) {
            cin >> pts[i].x >> pts[i].y;
        }
        if (check(n, k, pts)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}