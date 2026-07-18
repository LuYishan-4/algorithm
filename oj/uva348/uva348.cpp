#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[15][15];
int cutp[15][15];
int r[15], c[15];

string build(int l, int rr) {
    if (l == rr)
        return "A" + to_string(l);

    int k = cutp[l][rr];

    return "(" +
           build(l, k) +
           " x " +
           build(k + 1, rr) +
           ")";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int tc = 1;

    while (cin >> n && n) {

        for (int i = 1; i <= n; i++)
            cin >> r[i] >> c[i];

        memset(dp, 0, sizeof(dp));

        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {

                int rr = l + len - 1;
                dp[l][rr] = LLONG_MAX;

                for (int k = l; k < rr; k++) {
                    ll cost =  dp[l][k]+ dp[k + 1][rr]+ 1LL * r[l] * c[k] * c[rr];
                    if (cost < dp[l][rr]) {
                        dp[l][rr] = cost;
                        cutp[l][rr] = k;
                    }
                }
            }
        }

        cout << "Case " << tc++
             << ": "
             << build(1, n)
             << '\n';
    }
}