
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
#define pii pair<int, int>
#define f first
#define s second
int n, m, q, low[100001], disc[100001], t, p[100001];vector< pii > adj[100001];bool ans[1000001];
pii mp(int a, int b)
{
    pii temp;temp.f=a;temp.s=b;return temp;
}
void dfs(int i)
{
    disc[i]=low[i]=t++;
    for(auto j:adj[i])
    {
        if(disc[j.f]!=-1)
        {
            if(p[i]!=j.f)
            {
                low[i]=min(low[i], disc[j.f]);
            }
        }
        else
        {
            p[j.f]=i;
            dfs(j.f);
            low[i]=min(low[i], low[j.f]);
            if(low[j.f]>disc[i]) ans[j.s]=1;
        }
    }
}
signed main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    scanf("%d%d%d", &n, &m, &q);
    while(m--){
        int u, v, w;scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back(mp(v, w));        adj[v].push_back(mp(u, w));
    }
    t=0;
    for(int i=1;i<=n;i++)
    {
        disc[i]=-1;p[i]=-1;
    }
    for(int i=1;i<=n;i++)
    {
        if(disc[i]==-1) dfs(i);
    }
    while(q--)
    {
        int id;scanf("%d", &id);
        if(ans[id]) printf("YES\n");
        else printf("no\n");
    }
    return 0;
}