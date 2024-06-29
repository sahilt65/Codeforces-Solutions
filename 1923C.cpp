#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n,q;
	cin>>n>>q;
	int a[n+1];
	for(int i = 1; i<=n; i++) cin>>a[i];
	int pref[n+1];pref[0]=0;
	int cnt1[n+1];cnt1[0]=0;
	for(int i = 1; i<=n; i++){
		pref[i]=(pref[i-1]+a[i]);
		if(a[i]==1) cnt1[i]=(cnt1[i-1]+1);
		else cnt1[i]=(cnt1[i-1]);
	}
	for(int i = 0; i<q; i++){
		int l,r;
		cin>>l>>r;
		int tot1=(cnt1[r]-cnt1[l-1]);
		int sum=(pref[r]-pref[l-1]);
		sum-=(r-l+1);
		// d2(tot1,sum);
		if(tot1==0){
			if(l==r){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}
		}
		else{
			if(sum>=tot1){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return;

}
int main() {
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}