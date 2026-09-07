#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using  namespace std;
typedef long long ll ;
bool dp[100 + 5][100 * 100 + 5];
int main(){
	ll n,m;
	while (cin>>n>>m) {
		vector<ll> index(n+m+1);
		ll sum =0;
		for(ll i=1;i<=n+m;i++){
			cin>>index[i];
			sum+=index[i];
			index[i]+=50;
		}
		memset(dp, false, sizeof(dp));
		dp[0][0]=true;
		for(ll i=1;i<=n+m;i++)
			for(ll k=min(i,n);k>=1;k--)
				for(ll j=0;j<=10000;j++)
					if (dp[k-1][j])dp[k][j+index[i]] = true;
		ll maxi = -5000;
		ll mini = 5000;
		for(ll i=0;i<10000;i++){
			if(dp[n][i]){
				ll nsum = i-50*n;
				maxi = max(maxi, nsum*(sum-nsum));
				mini = min(mini, nsum*(sum-nsum));
			}		
		}
		cout<<maxi<<" "<<mini<<"\n";
	}
	return 0;
}