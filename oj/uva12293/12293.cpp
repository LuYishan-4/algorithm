#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll dd[501][501];
int main(){
	cin.tie(0)->sync_with_stdio(false);
	ll n;
	while (cin>>n && n) {
		bool another =true;
		while(n){
			if ((n-1)%2){
				another =false;
				break;
			}
			n = (n-1)/2;
		}
		if(another)cout<<"Bob"<<"\n";
		else cout<<"Alice"<<"\n";
	}
}