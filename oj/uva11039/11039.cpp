#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 
int p,f;
int main(){
	int ans;
	ll last;
	cin.tie(0)->sync_with_stdio(false);

	cin>>p;
	vector<ll> vec,stu;
	bool rev;
	for (int i=0;i<p;i++){
		ans = 1;
		cin>>f;
		vec.clear();
		stu.clear();
		ll value;
		for (int j =0;j<f;j++ ){
			cin>>value;
			vec.push_back(value);
		}
		sort(vec.begin(),vec.end(),[](auto a,auto b){
			return abs(a)<abs(b);
		});
		while (!vec.empty()){
			rev = true;
			last = vec.back();
			if (!stu.empty()&&stu[stu.size()-1]*last <0){
				ans+=1;
				stu.pop_back();
				rev = true;
			}else if (!stu.empty()&&stu[stu.size()-1]*last >0){
				rev = false;
			}
			if (rev)stu.push_back(last);
			vec.pop_back();
		}	
		cout<<ans<<"\n";
	}
}