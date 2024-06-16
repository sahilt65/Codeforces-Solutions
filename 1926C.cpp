#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll preSum[200001] = {0};

void initFun()
{
    for (int i = 1; i <= 200000; i++)
    {
        ll sum = 0;
        int num = i; 

        while (num > 0)
        {
            sum += (num % 10);
            num /= 10;
        }

        preSum[i] = preSum[i - 1] + sum; 
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    initFun();
    while(t--){
        ll n;
        cin>>n;
        cout<<preSum[n]<<endl;

    }
    return 0;
}