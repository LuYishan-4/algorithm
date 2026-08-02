#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<ll,ll>> dir = {
    {0,-1},
    {0,1},
    {1,0},
    {-1,0}
};
vector<string> mat;
ll n;

ll bfs(int mask) {
    vector<vector<ll>> dist(n, vector<ll>(n, -1));
    vector<pair<ll, ll>> que;
    
    char start_c = mat[0][0];
    if (islower(start_c)) {
        int id = start_c - 'a';
        if ((mask & (1 << id)) != 0) return -1;
    } else if (isupper(start_c)) {
        int id = start_c - 'A';
        if ((mask & (1 << id)) == 0) return -1;
    }

    que.push_back({0, 0});
    dist[0][0] = 1;
    ll head = 0;
    
    while (head < que.size()) {
        ll x = que[head].first;ll y = que[head].second;
        head++;
        if (x == n - 1 && y == n - 1) return dist[x][y];
        for (auto dd : dir) {
            ll nx = x + dd.first;ll ny = y + dd.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                char c = mat[nx][ny];
                bool blocked = false;
                
                if (islower(c)) {
                    int id = c - 'a';
                    if ((mask & (1 << id)) != 0) blocked = true;
                } else if (isupper(c)) {
                    int id = c - 'A';
                    if ((mask & (1 << id)) == 0) blocked = true;
                }
                if (!blocked) {
                    dist[nx][ny] = dist[x][y] + 1;
                    que.push_back({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main(){
	//cin.tie(0)->sync_with_stdio(false);
    while (cin >> n && n > 0) {
        mat.clear();
        mat.resize(n);
        for (int i = 0; i < n; i++) cin >> mat[i];
        ll min_ans = -1;
        for (int mask = 0; mask < (1 << 10); mask++) {
            ll res = bfs(mask);
            if (res != -1) {
                if (min_ans == -1 || res < min_ans) {
                    min_ans = res;
                }
            }
        }
        cout << min_ans << '\n';
    }
    return 0;
}