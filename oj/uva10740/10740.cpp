#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
struct point{
	ll to;
	ll w;
};
struct Egde{
	ll dist;
	ll u;
	bool operator>(const Egde& o)const{
		return dist>o.dist;
	}
};
ll bfs(ll n,ll s,ll t,ll k,const vector<vector<point>> &adj){
	priority_queue<Egde,vector<Egde>,greater<Egde>> pq;
	vector<ll> counter(n+1,0);
	pq.push({0,s});
	while (!pq.empty()) {
		Egde last=pq.top();
		pq.pop();
		ll nd = last.dist;ll nu = last.u;
		if(counter[nu]>=k)continue;
		counter[nu]++;
		if(counter[t] == k&&nu == t)return nd;
		for(const auto& egde :adj[nu])
			if(counter[egde.to] <k)pq.push({nd+egde.w,egde.to});
	}
	return -1;
}
int main(){
	cin.tie(0)->sync_with_stdio(false);
	ll n,m;
    while (cin>>n>>m &&(n != 0 || m != 0)) {
		ll s,t,k;
		cin>>s>>t>>k;
		vector<vector<point>> adj(n+1);
		for(ll i=0;i<m;i++){
			ll u,v,w;
			cin>>u>>v>>w;
			adj[u].push_back({v,w});
		}
		cout<<bfs(n,s,t,k,adj)<<"\n"; 
    }
	return 0;
}