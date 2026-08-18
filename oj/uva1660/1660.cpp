#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
typedef long long ll ;
struct edge {
    ll from, to, cap, flow;
    edge(ll u, ll v, ll c, ll f) : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic {
    vector<edge> edges;
    vector<vector<ll>> adj;
    vector<ll> level, ptr;
    int n, m = 0, s, t;
    Dinic(ll n, ll s, ll t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    void addEdge(int u, int v, int c) {
        edges.emplace_back(u, v, c, 0);
        edges.emplace_back(v, u, 0, 0);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1) continue;
                int v = edges[id].to;
                if (level[v] != -1) continue;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        return level[t] != -1;
    }
    int dfs(ll u, ll pushed) {
        if (pushed == 0) return 0;
        if (u == t) return pushed;
        for (ll &cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
            ll id = adj[u][cid];
            ll v = edges[id].to;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    ll flow() {
        int f = 0;
        while (true) {
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, INT_MAX)) {
                f += pushed;
            }
        }
        return f;
    }
};
int main() {
    ll n,m,ans;char c;
    while(cin>>n>>m){
    	ans=n;
    	vector<ll>s(m),t(m);
    	for(ll k=0;k<m;k++)cin>>c>>s[k]>>c>>t[k]>>c;
    	for(ll k=0;k<n-1;k++)for(ll i=k+1;i<n;i++){
    		Dinic dinic(n*2,n+k,i);
    		for(ll j=0;j<n;j++)dinic.addEdge(j, j+n, 1);
    		for(ll j=0;j<m;j++){
    			dinic.addEdge(s[j]+n, t[j], n);
    			dinic.addEdge(t[j]+n, s[j], n);
    		}
    		ans=min(ans,dinic.flow());
    	}
    	cout<<ans<<'\n';
    }
}