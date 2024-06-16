#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n+1);
        for(int i = 1; i<=n; i++) cin>>v[i];

        vector<int> pre(n+1);
        pre[0] = 0;
        pre[1] = 0;
        pre[2] =(1); 
        for(int i = 2; i<n; i++){
            int left = v[i] - v[i-1];
            int right = v[i+1] - v[i];
            if(left > right){
                pre[i+1] = 1 + pre[i];
            }else{
                pre[i+1] = right + pre[i];
            } 
            
        }
        

        vector<int> suff(n+1);
        suff[n] = 0;
        suff[n-1] = 1;
        for(int i = n-1; i>=2; i--){
            int left = v[i] - v[i-1];
            int right = v[i+1] - v[i];
            if(left < right){
                suff[i-1] = 1 + suff[i];
            }else{
                suff[i-1] = left + suff[i];
            } 
        }
    
        int m; cin>>m;
        while(m--){
            int x, y;
            cin>>x>>y;
            if(x<y){
                cout<<abs(pre[y]-pre[x])<<endl;
            }
            else{
                cout<<abs(suff[x]-suff[y])<<endl;
            }
        }
    }
    return 0;
}