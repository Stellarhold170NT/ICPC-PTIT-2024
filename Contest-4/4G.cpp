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

unordered_map<int, int > mp;
struct Matrix {
    int a, b, c, d;
};

Matrix I = { 1, 0, 1, 0 };

Matrix mul(Matrix a, Matrix b) {
    Matrix f;
    f.a = (a.a * b.a + a.b * b.c) % mod;
    f.b = (a.a * b.b + a.b * b.d) % mod;
    f.c = (a.c * b.a + a.d * b.b) % mod;
    f.d = (a.c * b.b + a.d * b.d) % mod;
    return f;
}

Matrix X = { 0, 1, 1, 1 };

Matrix powMatrix(int n) {
    Matrix result = I;
    Matrix base = X;

    while (n > 0) {
        if (n % 2 == 1) {
            result = mul(result, base);
        }
        base = mul(base, base);
        n /= 2;
    }

    return result;
}


int fibo(int n) {
    if (mp[n]) return mp[n];
    auto MT = powMatrix(n);
    return MT.b;

}
// DATA

struct Data {
    int fibo_a;
    int fibo_a_minus;
};

int n, m;
int A[N];
Data st[N << 2];
int sum[N << 2];
int lz[N << 2];

void build(int id, int L, int R) {
    if (L > R) return;
    if (L == R) {
        st[id].fibo_a = fibo(A[L]);
        st[id].fibo_a_minus = fibo(A[L] - 1);
        sum[id] = 0;
        return;
    }

    int mid = (L + R) / 2;
    build(id * 2, L, mid);
    build(id * 2 + 1, mid + 1, R);

    st[id].fibo_a = (st[id * 2].fibo_a + st[id * 2 + 1].fibo_a) % mod;
    st[id].fibo_a_minus = (st[id * 2].fibo_a_minus + st[id * 2 + 1].fibo_a_minus) % mod;
}

inline void calc(int id) {
    int a = (st[id].fibo_a * fibo(sum[id] + 1)) % mod + (st[id].fibo_a_minus * fibo(sum[id])) % mod;
    int b = (st[id].fibo_a * fibo(sum[id])) % mod + (st[id].fibo_a_minus * fibo(sum[id] - 1)) % mod;
    st[id].fibo_a = a % mod;
    st[id].fibo_a_minus = b % mod;
}

inline void lazy(int id, int L, int R) {
    if (sum[id]) {
        sum[id * 2] += sum[id];
        sum[id * 2 + 1] += sum[id];
        calc(id * 2);
        calc(id * 2 + 1);
        sum[id] = 0;
    }
}

void update(int id, int qL, int qR, int L, int R, ll X) {
    lazy(id, L, R);

    if (L > R || R < qL || L > qR) return;

    if (L >= qL && R <= qR) {
        sum[id] += X;
        lz[id] += X;
        return;
    }

    int mid = (L + R) / 2;

    update(id * 2, qL, qR, L, mid, X);
    update(id * 2 + 1, qL, qR, mid + 1, R, X);

    st[id].fibo_a = (st[id * 2].fibo_a + st[id * 2 + 1].fibo_a) % mod;
    st[id].fibo_a_minus = (st[id * 2].fibo_a_minus + st[id * 2 + 1].fibo_a_minus) % mod;

}

int query(int id, int qL, int qR, int L, int R) {
    lazy(id, L, R);

    if (L > R || R < qL || L > qR) return 0;

    if (L >= qL && R <= qR) {
        return st[id].fibo_a;
    }

    int mid = (L + R) / 2;

    return (query(id * 2, qL, qR, L, mid) + query(id * 2 + 1, qL, qR, mid + 1, R)) % mod;
}


signed main() {
    sclld2(n, m);
    for (int i = 0; i < n; i++) sclld(A[i]);

    build(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int t, l, r;
        ll x;

        sclld3(t, l, r);

        if (t == 1) {
            sclld(x);
            update(1, l - 1, r - 1, 0, n - 1, x);
        }
        else if (t == 2) {
            ll ans = query(1, l - 1, r - 1, 0, n - 1);
            printf("%lld\n", ans);
        }

    }

    return 0;
}