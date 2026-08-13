#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
//slide window
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0)->sync_with_stdio(false);
	ll n;
	if (cin>>n) {
		while(n--){
			ll m;
			cin>>m;
			vector<ll> snow(m);
			for (ll i=0;i<m;i++)cin>>snow[i];
			unordered_map<ll,ll> fin;
			ll ans=0,left =0;
			for (ll right =0;right<m;right++){
				ll ck = snow[right];
				if(fin.find(ck)!=fin.end() && fin[ck] >= left)left=fin[ck]+1;
				fin[ck] = right;
				ans = max(ans,right-left+1);
			}
			cout<<ans<<"\n";
		}
	}
    return 0;
}
