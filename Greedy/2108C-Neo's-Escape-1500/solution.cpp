#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int msize=2e5+5;
int a[msize];

signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int k=0, ans=0;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i] != a[i-1])
                a[++k]=a[i];
            else
                continue;
        }
        a[0]= a[k+1] =0;
        for(int i=1;i<=k;i++)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1])
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}