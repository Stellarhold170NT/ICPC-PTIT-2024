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
//#define A (ll)911382323
//#define A (ll)131
//#define B (ll)972663749
//#define A (ll)3
//#define B (ll)97
//const int N = 1e6;
const int M = 1000;
const int MAX = 1;

signed main() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    vector<int> pfA(n + 1, 0), pfB(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pfA[i] ^= a[i] ^ pfA[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        pfB[i] ^= b[i] ^ pfB[i - 1];
    }

    vector<pair<int, int>> result;

    auto check = [&](int l, int r, int u, int v, int val) {
        int d = r - l + 1;
        for (int i = 17; i >= 0; i--) {
            if (d & (1 << i)) {
                int r1 = pfA[l + (1 << i) - 1] ^ pfA[l - 1];
                int r2 = pfB[u + (1 << i) - 1] ^ pfB[u - 1];
                if (i == 0 && r1 ^ r2 == val) return true;
                if (r1 != r2) return false;
                l += (1 << i);
                u += (1 << i);
            }
        }
        return true;
    };

    for (int k = 0; k < n; k++) {
        int x = a[k + 1] ^ b[1];
        bool valid = true;
        int l = k + 1, r = n;
        int v = 1 + r - l;
        valid = check(l, r, 1, v, x);
        if (k > 0) {
            valid &= check(1, k, n - k + 1, n, x);
        }

        if (valid) {
            result.push_back({ k, x });
        }
    }

    for (auto& p : result) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
