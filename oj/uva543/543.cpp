#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll ;

#define INF 100005
vector<bool> prime(INF,true);
void slove(ll const &n){
	for(ll i=3;i<=n/2;i+=2)
		if(prime[i]){
			ll j=n-i;
			if(prime[j]){
				cout<<n<<"="<<i<<"+"<<j<<'\n';
				return;
			}
		}
	cout<<"Goldbach's conjecture is wrong.";
}

int main(){
	cin.tie(0)->sync_with_stdio(false); 
	prime[0]=prime[1]=false;
	for(ll i=2;i*i<INF;i++){
		if (prime[i]) {
			for(ll j=i*i;j<INF;j+=i){
				prime[j] =false;
			}
		}
	}
	ll n;
	while (cin>>n&& n != 0){
		slove(n);
	}
	return 0;
}