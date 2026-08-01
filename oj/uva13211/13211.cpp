#include <bits/stdc++.h>
#include <iostream>
using namespace  std;
typedef  long long ll ;
ll score[501][501];
ll d[501];

int main(){
	ll n,t;
	cin.tie(0)->sync_with_stdio(false);
	cin>> t;
	while (t--) {
		cin>>n;
		for(ll i =0;i<n;i++)for(ll j =0;j<n;j++){
			cin>>score[i][j];
		}
		for(ll i =0;i<n;i++)cin>>d[i];
		ll re =0;
		for(ll i =n-1;i>=0;i--){
				ll x = d[i];
				for (ll j=0;j<n;j++){
					for (ll k=0;k<n;k++){
					score[j][k] = min(score[j][k],score[j][x]+score[x][k]);
				}
		}
		ll tmp =0;
		for (ll c =i;c<n;c++){
			ll u1 = d[c];
			for (ll vv =c+1;vv<n;vv++){
				ll v1 = d[vv];
				tmp +=score[u1][v1]+score[v1][u1];
			}
		}
			re=re + tmp;
		}
		cout<<re<<'\n';
	}
	
	return 0;
	}
