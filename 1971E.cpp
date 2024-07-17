#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n,k,q;
	cin>>n>>k>>q;
	
	int a[k+1], b[k+1]; 
	a[0]=0; b[0]=0;
	
	for(int i=1;i<=k;i++){
	    cin>>a[i];
	}
	for(int i=1;i<=k;i++){
	    cin>>b[i];
	}

    while(q--){
        int d;
	    cin>>d;
	    
	    if(d==0){cout<<0<<" "; continue;}
	    if(d==n){cout<<b[k]<<" "; continue;}
 
	    int ind = upper_bound(a,a+k+1,d) - a;
	    int ans = b[ind-1];
	    
	    int dist = a[ind] - a[ind-1];
	    int time_taken = b[ind] - b[ind-1] ;
	    
	    int extra_dist_to_cover = d-a[ind-1];
	    int extra_time = (extra_dist_to_cover*time_taken)/(dist);
	    ans+=extra_time;
	    
	    cout<<ans<<" ";
    }
    cout<<endl;

}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}