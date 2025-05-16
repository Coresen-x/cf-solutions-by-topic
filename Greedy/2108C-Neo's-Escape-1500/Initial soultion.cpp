#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int msize=2e5+5;
struct node {
    int val, pos;
};
bool cmp(node a, node b) {  
    return a.val > b.val;
}
node a[msize], p[msize];

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
        {
            cin >> a[i].val;
            a[i].pos=i;
            p[i] = a[i];
            // 需要记录原数组。
        }
        sort(a+1, a+n+1, cmp);
        int ans=0;
        vector<int> vis(n+1, 0);
        for(int i=1;i<=n;i++)
        {
            node tmp=a[i];
            if(a[i].val != a[i-1].val)
            {
                queue<node> q;
                for(int k=i;k<=n;k++)
                {
                    if(a[k].val != tmp.val) break;
                    if(vis[a[k].pos]) 
                        q.push(a[k]);               
                }
                while(!q.empty())
                {
                    node u=q.front();
                    q.pop();
                    if(u.pos+1<=n && p[u.pos+1].val == u.val)
                        if(!vis[u.pos+1])
                            q.push(p[u.pos+1]);
                    if(u.pos-1>=1 && p[u.pos-1].val == u.val)
                        if(!vis[u.pos-1])
                            q.push(p[u.pos-1]);
                    vis[u.pos]=vis[u.pos+1]=vis[u.pos-1]=1;
                }
            }
            if(!vis[tmp.pos])
            {
                ans++;
                queue<node> q;
                q.push(tmp);
                while(!q.empty())
                {
                    node u=q.front();
                    q.pop();
                    // 因为没有初始化、导致的出界。
                    if(u.pos+1<=n && p[u.pos+1].val == u.val)
                        if(!vis[u.pos+1])
                            q.push(p[u.pos+1]);
                    if(u.pos-1>=1 && p[u.pos-1].val == u.val)
                        if(!vis[u.pos-1])
                            q.push(p[u.pos-1]);
                    vis[u.pos]=vis[u.pos+1]=vis[u.pos-1]=1;
                }
            }
            vis[tmp.pos] = vis[tmp.pos+1] = vis[tmp.pos-1] = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}