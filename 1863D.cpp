#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<char> > v(n, vector<char> (m));
    vector<int> cols(m), rows(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
        }
    }
    

    for(int j = 0; j<m; j++){
        int cnt = 0;
        for(int i = 0; i< n; i++){
            if(v[i][j] == 'L'){
                cnt++;
            }
        }
        if(cnt%2 != 0){
            cout<<"-1"<<endl;
            return;
        }

        cols[j] = cnt;
    }

    for(int i = 0; i<n; i++){
        int cnt =0;
        for(int j= 0; j<m; j++){
            if(v[i][j] == 'U'){
                cnt++;
            }
        }

        if(cnt%2 != 0){
            cout<<"-1"<<endl;
            return;
        }
        rows[i] = cnt;
    }

    for(int i=0;i<n;i++){
		int x = rows[i];
		if(!x)continue;
		x /= 2;
		for(int j=0;j<m;j++){
			if(v[i][j]=='U'){
				if(x){
					if(v[i][j]=='U'){
						v[i+1][j] = 'B';
					}
					v[i][j] = 'W';
					x--;
				}else{
					v[i][j] = 'B';
					v[i+1][j] = 'W';
				}
			}
		}
	}
	for(int j=0;j<m;j++){
		int x = cols[j];
		if(!x)continue;
		x/=2;
		for(int i=0;i<n;i++){
			if(v[i][j]=='L'){
				if(x){
					v[i][j] = 'W';
					v[i][j+1] = 'B';
					x--;
				}else{
					v[i][j] = 'B';
					v[i][j+1] = 'W';
				}
			}
		}
	}
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return;
}
int main() {
    int t; 
    cin>>t; 
    while(t--) solve();
    return 0;
}