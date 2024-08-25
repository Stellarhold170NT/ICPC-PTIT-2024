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
const int N = 2e5 + 1;
const int logN = 18;
const int M = 20;
const int MAX = 1;

int bit[N] = { 0 };
int bit1[N] = { 0 };

void update(int x, int val) {
    while (x > 0) {
        bit[x] += val;
        x -= x & (-x);
    }
}

int get(int x) {
    int ans = 0;
    while (x < N) {
        ans += bit[x];
        x += x & (-x);
    }
    return ans;
}

void update1(int x, int val) {
    while (x < N) {
        bit1[x] += val;
        x += x & (-x);
    }
}

int get1(int x) {
    int ans = 0;
    while (x > 0) {
        ans += bit1[x];
        x -= x & (-x);
    }
    return ans;
}

signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    vector<int> compressed_v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

    for (int i = 0; i < n; i++) {
        compressed_v[i] = lower_bound(sorted_v.begin(), sorted_v.end(), v[i]) - sorted_v.begin() + 1;
    }

    int sum = 0;
    int ans = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        sum += get(compressed_v[i] + 1);
        update1(compressed_v[i], 1);
        if (sum >= k) {
            while (j < i) {
                int smaller = get1(compressed_v[j] - 1);
                if (sum - smaller >= k) {
                    sum -= smaller;
                    update(compressed_v[j], -1);
                    update1(compressed_v[j], -1);
                    j++;
                }
                else break;
            }
            ans += j + 1;
        }
        update(compressed_v[i], 1);
    }

    cout << ans << endl;

    return 0;
}