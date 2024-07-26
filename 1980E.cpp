#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

void solve() {
    int n, m;
    cin>>n>>m;

    vector<vector<int> > a(n, vector<int> (m));
    vector<vector<int> > b(n, vector<int> (m));
    set<vector<int> > c;
    set<vector<int> > r;
    for(int i= 0; i<n; i++){
        vector<int> v(m);
        for(int j = 0; j<m; j++){
            
            cin>>a[i][j];
            v[j] = a[i][j];
        }

        sort(v.begin(), v.end());
        r.insert(v);
    }

    for(int i= 0; i<n; i++){
        vector<int> v(m);
        for(int j = 0; j<m; j++){
            cin>>b[i][j];
            v[j] = b[i][j];
        }
        sort(v.begin(), v.end());
        r.insert(v);
    }

    for(int j = 0; j<m; j++){
        vector<int> v(n);
        vector<int> t(n);
        for(int i = 0; i<n; i++){
            v[i] = a[i][j];
            t[i] = b[i][j];
        }
        sort(v.begin(), v.end());
        sort(t.begin(), t.end());
        c.insert(v);
        c.insert(t);
    }

    if(c.size() != m || r.size() != n){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    
}

void solve2(){
    int n, m;
    cin>>n>>m;

    vector<vector<int> > a(n, vector<int> (m));
    vector<vector<int> > b(n, vector<int> (m));
    vector<pair<int, int> > t(n*m);
    for(int i= 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>a[i][j];
            t[a[i][j]] = {i, j};
        }
    }
    for(int i= 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>b[i][j];
        }
    }

    int row = 0;
    bool ans = true;
    for(int i= 0; i<n; i++){
        row = t[b[i][0]-1].first;
        for(int j = 0; j<m; j++){
            if(t[b[i][j]-1].first != row){
                ans = false;
                break;
            }
        }
    }

    if(!ans){
        cout<<"NO"<<endl;
        return;
    }
    int col = 0;
    for(int j = 0; j<m; j++){
        col = t[b[0][j]-1].first;
        for(int i = 0; i<n; i++){
            if(col != t[b[i][j]-1].second){
                ans = false;
                break;
            }
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) solve2();
    return 0;
}