#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        if((n == 1 && m == 1 )) {
            cout<<"-1"<<endl;
            continue;
        }

        if(n==1){
            if(m%2==1){
                reverse(a[0].begin(), a[0].end());
                for(int i = 0; i<n; i++){
                    for(int j = 0; j<m; j++){
                        cout<<a[i][j]<<" ";
                    }
                    cout<<endl;
                }
                continue;
            }
            
        }

        if(m == 1){
                
            for(int i = n-1; i>=0; i--){
                cout<<a[i][0]<<" ";
                cout<<endl;
            }
            continue;
        }
        

        vector<vector<int> > b(n, vector<int>(m));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m-1; j++){
                swap(a[i][j], a[i][j+1]);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
