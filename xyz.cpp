#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<int> &v) {
    set<int> s;
    for(int i = 0; i<v.size(); i++){
        vector<int> temp;
        int t = v[i];

        while(t>0){
            int curr = t % 10;
            t /= 10;
            temp.push_back(curr);
        }
        reverse(temp.begin(), temp.end());
        if(temp[temp.size()- 1] == 0){
            temp.pop_back();
        }

        sort(temp.rbegin(), temp.rend());

        for(int j = 0; j<temp.size(); j++){
            s.insert(temp[i]);
        }
    }

    for(auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main() {
    vector<int> v = {3560, 105, 694, 23, 690};
    solve(v);
    return 0;
}