#include <bits/stdc++.h>

using namespace std;

struct abw{
	int a;int b;int c;
};

vector<abw> egde;
vector<int> par;
vector<int> weight;

int findroot(int i){
	if (par[i] == i)return i;
	return par[i] = findroot(par[i]);
}
bool iscy(int a,int b){
	int u = findroot(a);
	int v = findroot(b);
	if(u==v)return false;
	if(weight[u] > weight[v])par[v] = u;
	else if(weight[u] < weight[v])par[u] =v;
	else par[v] = u, ++weight[u];
	
	
	
	return true;
}


void  kruskcal(){
	bool forest = true;
	for(auto &p:egde){
		if(iscy(p.a,p.b))continue;
		if (!forest)cout << " ";
		cout << p.c;
		forest = false;
	}
	if (forest) cout << "forest";
	cout<< "\n";
}

int main(){
	cin.tie(0)->sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m;
	while(cin>>n>>m, n && m){
		egde.clear();
		par.clear();
		weight.assign(n,0);
		for (int i =0;i<n;i++)par.push_back(i);
		for (int i =0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			egde.push_back({a,b,c});
		}
		sort(egde.begin(),egde.end(),[](const abw &a,const abw &b){
			return a.c < b.c;
		});
		kruskcal();
	}	
	return 0;
}
	
	

		
		
		

