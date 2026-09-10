#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll ;

struct Egde{
	ll u,v,w;
	bool operator<(const Egde& o)const{
		return w>o.w;
	}
};
struct DisjointSet {
	vector<ll> parent;
	DisjointSet(ll n){
		parent.resize(n+1);
		for(ll i=1;i<=n;i++)parent[i] = i;
	}
	ll find(ll i){
		if(parent[i] ==i )return i;
		return parent[i] = find(parent[i]);
	}
	bool unite(ll i,ll j){
		ll ri = find(i);ll rj =find(j);
		if (ri != rj){
			parent[ri] =rj;
			return true;
		}
		return false;
	}
};
int main(){
	cin.tie(0)->sync_with_stdio(false);
	ll c,n,m;
	cin>>c;
	while (c--) {
		cin>>n>>m;
		vector<Egde> egde(m);
		for (ll i = 0; i < m; ++i) {
		        cin >> egde[i].u >> egde[i].v >> egde[i].w;
		}
		sort(egde.begin(), egde.end());
		DisjointSet ds(n);
		ll sum =0;
		for(const auto& egdes:egde)
		 if (!ds.unite(egdes.u, egdes.v ))sum+=egdes.w;
		 cout<<sum<<'\n';
	}

}