#include <bits/stdc++.h>
using namespace std;

int vis[105][105];

vector<pair<int,int>> dir={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
int dfs(int x,int y,vector<string>& mp){
    int n = mp.size();
    int m = mp[0].size();
    if(x < 0 || x >= n || y < 0 || y >= m)
        return 0;
    if(vis[x][y] || mp[x][y] == '1')
        return 0;
    vis[x][y] = true;
    int ans = 1;
	for(auto [dx,dy]:dir){
	     ans+=dfs(x+dx,y+dy,mp);
	 }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        vector<string> mp;
        string s;
        cin >> ws;
        getline(cin,s);
        int x = stoi(s.substr(0,2));
        int y = stoi(s.substr(3,2));
        while(getline(cin,s)){
            if(s.empty()) break;
            mp.push_back(s);
        }
        memset(vis,false,sizeof(vis));
        cout << dfs(x-1,y-1,mp) << "\n";
        if(T) cout << "\n";
    }

    return 0;
}