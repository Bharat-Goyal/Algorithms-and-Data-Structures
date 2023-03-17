#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 1000000000
#define pii pair<int, int>
#define f first
#define s second
#define mp make_pair
vector< pii > adjlist[10001];vector<int> dist(10001, INT_MAX);int n, m;vector<bool> included(10001, false);
priority_queue< pii, vector< pii >, greater< pii > > pq;
signed main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a, b, c;cin>>a>>b>>c;adjlist[a].push_back(mp(c, b));
    }
    pq.push(mp(0, 1));
    int cur, w;dist[1]=0;
    while(!pq.empty())
    {
        cur=pq.top().s;w=pq.top().f;pq.pop();
        if(included[cur]||w>dist[cur]) continue;
        included[cur]=true;
        for(int i=0;i<adjlist[cur].size();i++)
        {
            int next=adjlist[cur][i].s, add=adjlist[cur][i].f;
            if(dist[next]>dist[cur] + add)
            {
                dist[next]=dist[cur]+add;pq.push(mp(dist[next], next));
            }
        }
    }
    for(int i=2;i<=n;i++) 
    {   if(dist[i]==INT_MAX) cout<<MAX<<" ";
        else cout<<dist[i]<<" ";}
}