#include <bits/stdc++.h>
using namespace std;
const int msize=2e5+5;
int a[msize];

signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        
        int cnt=0;
        vector<int> vis(n+1, 0);
        for(int i=1;i<=n;i++)
        {
            if(!vis[a[i]])
            {
                vis[a[i]]=1;
                cnt++;
            }
        }

        if(cnt == n)
        {
            int l, r;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) l=i;
                if(a[i]==n) r=i;
            }
            int tmp1, tmp2;
            cout << "? " << l << ' ' << r << endl;
            cin >> tmp1;
            cout << "? " << r << ' ' << l << endl;
            cin >> tmp2;
            if(tmp1 == tmp2 && tmp1 >= abs(n-1))
                cout << "! B" << endl;
            else   
                cout << "! A" << endl;
        }
        else
        {
            int ptr, k=1, tmp;
            for(int i=1;i<=n;i++)
                if(!vis[i]) 
                {
                    ptr=i;
                    break;
                }
            // 对于从未出现的顶点, 其有向图一定为0(作为起始点)
            // 关键就在于如何让B类有值, 以区分二者.
            while(k<=n) { if(a[ptr]!=a[k]) break; k++; }
            cout << "? " << ptr << ' ' << k << endl;
            cin >> tmp;
            if(tmp==0) cout << "! A" << endl;
            else       cout << "! B" << endl;
        }
    }
    return 0;
}
