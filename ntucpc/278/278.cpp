#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,w;
    cin>>n>>w;
    map<long long,long long>better;
    long long plus = 0;
    for (int i = 0;i<n;i++){
        long long  a,b,c;
        cin>>a>>b>>c;
        plus+=a+b;
        if (better.empty()|| a > better[c])better[c] = a;
    }
    vector<long long>dp(w+1,plus);
    for (auto [cost,val]: better){
        for (int k = cost;k<=w;k++){
            dp[k] = max(dp[k],dp[k-cost]+val);
        }
    }
    cout<<dp[w]<<"\n";
    return 0;
}
