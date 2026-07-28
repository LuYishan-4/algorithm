#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <iostream>
#include <numeric>
using namespace  std;
int m,n;
vector<int> len;
bool dfs(const int& lenh,int start,int nt,vector <bool> vis,int nn){
	if (nn ==3)return true;
	if (nt == lenh)if(dfs(lenh,0,0, vis, nn+1))return true;
	for (int i =start;i<n;i++)if (!vis[i]&& nt+len[i]<=lenh){
		vis[i] = true;
		if (dfs(lenh,start+1, nt+len[i], vis, nn))return true;
		vis[i]=false;
	}
	return false;
}
int main(){
	cin.tie(0)->sync_with_stdio(false);
	cin>>m;
	while (m--) {
		len.clear();
		cin>>n;
		for(int i=0;i<n;i++){
			int cc;
			cin>>cc;
			len.push_back(cc);
		}
		sort(len.begin(),len.end(),greater<int>());
		int total = accumulate(len.begin(),len.end(),0);
	 	vector <bool> vis(n,false);
		if(dfs(total/4,0,0,vis,0))cout<<"yes"<<"\n";
		else cout<<"no"<<"\n";
	}
	return 0;
}