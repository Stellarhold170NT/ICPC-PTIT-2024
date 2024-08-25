#include<bits/stdc++.h>

using namespace std;

struct Ln {
    long long m, b;
};

deque<Ln> H;

bool cmp(pair<long long, long long> f1, pair<long long, long long> f2) {
    return f1.first * f2.second < f2.first * f1.second;
}

pair<long long, long long> isect(Ln l1, Ln l2) {
    return {l2.b - l1.b, l1.m - l2.m};
}

int main() {
    int n;
    long long c;
    cin >> n >> c;

    vector<long long> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<long long> dp(n + 1, LLONG_MAX);
    dp[1] = 0;

    H.emplace_back(Ln{-2 * x[1], x[1] * x[1] + dp[1]});

    for (int i = 2; i <= n; ++i) {
        while (H.size() >= 2 && cmp(isect(H[0], H[1]), {x[i], 1})) {
            H.pop_front();
        }
        dp[i] = x[i] * x[i] + c + H[0].m * x[i] + H[0].b;

        if (i == n) {
            break;
        }

        Ln nl = {-2 * x[i], x[i] * x[i] + dp[i]};
        while (H.size() > 1) {
            Ln ll = H.back();
            H.pop_back();
            Ln pl = H.back();
            H.pop_back();

            auto lc = isect(ll, pl);
            auto pt = isect(nl, ll);

            H.push_back(pl);

            if (cmp(lc, pt)) {
                H.push_back(ll);
                H.push_back(nl);
                break;
            }
        }
        if (H.size() <= 1) {
            H.push_back(nl);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
