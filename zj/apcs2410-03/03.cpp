//refer https://hackmd.io/@bangyewu/rJ5yJqEe1x

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll ;
ll m,n,req;
ll mat[501][501],dis[501][501],alldd[501][501];
vector<pair<ll,ll>> dire = {{0,1},{1,0},{-1,0},{0,-1}};

void  bfs(ll x,ll y,ll maxstep,vector<pair<ll,ll>> &que){
	ll head =0,i,j;
	for (i=max(x-maxstep,(ll)0);i<=min(y+maxstep,m-1);i++) {
	    for (j=max(y-maxstep,(ll)0);j<=min(y+maxstep,n-1);j++) {
	        dis[i][j] = (mat[i][j]==-1)? 0: -1;
	    }
	}
	que.push_back({x,y});
	dis[x][y] =0;
	while (head < (ll)que.size()) {
		x= que[head].first;
		y = que[head].second;
		head ++;
		if (dis[x][y] >=maxstep)continue;
		for (auto di:dire){
			ll nx = x+di.first;ll ny = y+di.second;
			if (nx >= 0 && nx < m&& ny >=0 && ny <n && dis[nx][ny] ==-1){
				dis[nx][ny] = dis[x][y] +1;
				que.push_back({nx,ny});
			}
		}
	}
	return;
}
ll dfs(ll x,ll y){
	ll ans =1,rad = mat[x][y];
	mat[x][y] = -2;
	if (x == 0)return ans;
	vector<pair<ll,ll>> quet;
	bfs(x,y,rad,quet);
	for (auto v:quet){
		if (mat[v.first][v.second] != -2){
			ans +=dfs(v.first,v.second);
		}
	}
	return ans;
}
int main(){
	cin.tie(0)->sync_with_stdio(false);
	ll s1,s2,x,y,ans=1;
	cin>>m>>n>>req;
	for(ll i=0;i<m;i++)for(ll j=0;j<n;j++){
		cin>>mat[i][j];
		if(mat[i][j] == -2)s1=i;s2 = j;
	}
	vector<pair<ll,ll>> quee;
	bfs(s1,s2,m*n,quee);
	for(ll i=0;i<m;i++)for(ll j=0;j<n;j++)alldd[i][j] = dis[i][j];
	for (auto q:quee){
		x = q.first;y =q.second;
		if (mat[x][y] == -2)continue;
		ans +=dfs(x,y);
		if (ans>=req) {
		    cout << alldd[x][y];
		    break;
		}
	}
	return 0;
}

