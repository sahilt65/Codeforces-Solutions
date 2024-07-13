#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
void printFunc(vector<string> &a, vector<string> &b, vector<string> &c, vector<string> &d){
    int last = 0;
    //Print A
    for(int i = 1; i<a.size(); i+=2){
        cout<<a[i-1]<<" "<<a[i]<<endl;
    }

    if(a.size()%2 > 0){
        cout<<a[a.size()-1]<<" "<<d[last]<<endl;;
        last++;
    }

    //Print B
    for(int i = 1; i<b.size(); i+=2){
        cout<<b[i-1]<<" "<<b[i]<<endl;
    }

    if(b.size()%2 > 0){
        cout<<b[b.size()-1]<<" "<<d[last]<<endl;;
        last++;
    }

    //Print C
    for(int i = 1; i<c.size(); i+=2){
        cout<<c[i-1]<<" "<<c[i]<<endl;
    }

    if(c.size()%2 > 0){
        cout<<c[c.size()-1]<<" "<<d[last]<<endl;
        last++;
    }

    //Trump Suit
    for(int i = last+1; i<d.size(); i+=2){
        cout<<d[i-1]<<" "<<d[i]<<endl;
    }
}
void solve() {
    int n;
    cin>>n;
    char ch;
    cin>>ch;
    vector<string> c, d, s, h;

    for(int i = 0; i<2 * n; i++){
        string temp;
        cin>>temp;

        if(temp[1] == 'C') c.push_back(temp);
        else if(temp[1] == 'D') d.push_back(temp);
        else if(temp[1] == 'S') s.push_back(temp);
        else h.push_back(temp);
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    sort(h.begin(), h.end());
    sort(s.begin(), s.end());
    int len = 0;
    if(ch == 'C'){
        len = c.size();
        if(d.size()%2!=0) len--;
        if(s.size()%2!=0) len--;
        if(h.size()%2!=0) len--;
    }else if(ch == 'D'){
        len = d.size();
        if(c.size()%2!=0) len--;
        if(s.size()%2!=0) len--;
        if(h.size()%2!=0) len--;
    }else if(ch == 'H'){
        len = h.size();
        if(c.size()%2!=0) len--;
        if(s.size()%2!=0) len--;
        if(d.size()%2!=0) len--;
    }else{
        len = s.size();
        if(c.size()%2!=0) len--;
        if(h.size()%2!=0) len--;
        if(d.size()%2!=0) len--;
    }

    if(len%2 > 0 || len < 0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    if(ch== 'C'){
        printFunc(d, h, s, c);
    }else if(ch == 'S'){
        printFunc(d, h, c, s);
    }else if(ch == 'D'){
        printFunc(h, c, s, d);
    }else{
        printFunc(d, c, s, h);
    }

}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}