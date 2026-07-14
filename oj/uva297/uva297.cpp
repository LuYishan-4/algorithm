#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll ;
ll idx;
vector<vector<int>> mat(32,vector<int>(32,0));
void slove(const string& line,int len,int x,int y){
    idx++;
    if (idx>line.length())return;
    if (line[idx] == 'p'){
        slove(line,len/2,x,y);
        slove(line,len/2,x,y+len/2);
        slove(line,len/2,x+len/2,y);
        slove(line,len/2,x+len/2,y+len/2);
    }else if (line[idx] == 'f'){
        for(int i=x;i<x+len;i++){
            for(int j=y;j<y+len;j++){
                mat[i][j]=1;
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,ans;
    cin >>n;
    string s;
    for (int i = 0;i<n;i++){
        for (auto& row:mat)fill(row.begin(), row.end(),0);
        ans = 0;
        for (int j=0;j<2;j++){
            idx = -1;
            cin>>s;
            slove(s,32,0,0);
        }
        for(int i=0;i<32;i++){
            for(int j=0;j<32;j++){
                ans+=mat[i][j];
            }
        }
        cout << "There are "
        << ans
        << " black pixels.\n";
    }
}
