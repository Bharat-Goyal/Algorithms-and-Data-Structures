//travel in hackerland     
#include<bits/stdc++.h>
using namespace std;
#define int long long
int par[100001][17], n, m, q;set<int> srank[100001][17];int ans[100001], val[100001], sprev[17];
vector<int> v;
struct node
{
    int u, v, w;
};
node edges[100001], queries[100001];
bool sf(node a, node b)
{
    return a.w<b.w;
}
int find(int i, int lvl)
{
    if(par[i][lvl]!=i) par[i][lvl]=find(par[i][lvl], lvl);
    return par[i][lvl];
}
void UNION(int a, int b, int lvl)
{
    if(srank[a][lvl].size()<srank[b][lvl].size()) swap(a, b);
    srank[a][lvl].insert(srank[b][lvl].begin(), srank[b][lvl].end());
    par[b][lvl]=a;
}
void upd(int i, int lvl)
{
    int u=edges[i].u, v=edges[i].v, w=edges[i].w;
    u=find(u, lvl);v=find(v, lvl);
    if(u==v) return;
    UNION(u, v, lvl);
}
int p(int i, int lvl)
{
    int u=queries[i].u, v=queries[i].v, req=queries[i].w;
    u=find(u, lvl);v=find(v, lvl);

    if(u!=v) return false;
    return srank[u][lvl].size();
}
void rec(int l, int r, int lvl, vector<int> &rem)
{
    if(rem.empty()) return;
    if(l==r)
    {
        for(auto i:rem) ans[i]=edges[l].w;
        return;
    }
    int mid=(l+r)>>1;
    while(sprev[lvl]<=mid)
    {
        upd(sprev[lvl], lvl);sprev[lvl]++;
    }
    vector<int> v1, v2;
    for(auto i:rem)
    {
        if(p(i, lvl)>=queries[i].w)
        {
            v1.push_back(i);
        }
        else v2.push_back(i);
    }
    rec(l, mid, lvl+1, v1);rec(mid+1, r, lvl+1, v2);
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=0;i<17;i++) {sprev[i]=0;
                          for(int j=1;j<=n;j++) {srank[j][i].insert(val[j]);par[j][i]=j;}
                          }
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    sort(edges, edges+m, sf);
    for(int i=0;i<q;i++)
    {
        cin>>queries[i].u>>queries[i].v>>queries[i].w;
        v.push_back(i);
    }
    rec(0, m-1, 0, v);
    while(sprev[0]<=m-1)
    {
        upd(sprev[0], 0);sprev[0]++;
    }
    for(int i=0;i<q;i++)
    {
        if(p(i, 0)<queries[i].w) cout<<-1<<endl;
        else cout<<ans[i]<<endl;
    }
}