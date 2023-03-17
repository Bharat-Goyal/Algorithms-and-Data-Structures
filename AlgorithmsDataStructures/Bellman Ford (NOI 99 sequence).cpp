/*
https://wcipeg.com/problem/noi99p1
The solution is a modification of the standard Bellman Ford algorithm. 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1001;
const int mod=1e9 + 7;
#define int long long
const int inf=1e18;
#define pii pair<int, int>
#define f first
#define s second 
#define mp make_pair
struct node
{
	int u, v, w;
};
node mn(int u, int v, int w)
{
	node t;t.u=u;t.v=v;t.w=w;return t;
}
int n, dist[N], a0, b0, l0, a1, b1, l1;vector< node > edges;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>a0>>b0>>l0>>a1>>b1>>l1;
	for(int i=1;i<=n;i++)
	{
		dist[i]=inf;
		edges.push_back(mn(i, i-1, 1));edges.push_back(mn(i-1, i, 0));
		if(i>=l0)
		{
			edges.push_back(mn(i, i-l0, l0-a0));edges.push_back(mn(i-l0, i, b0-l0));
		}
		if(i>=l1)
		{
			edges.push_back(mn(i, i-l1, b1));edges.push_back(mn(i-l1, i, -a1));	
		}
	}
	dist[0]=0;
	for(int i=1;i<n;i++){
		for(auto j:edges)
		{
			dist[j.v]=min(dist[j.v], dist[j.u] + j.w);
		}
	}
	for(auto j:edges)
	{
		if(dist[j.v]>dist[j.u] + j.w)
		{
			cout<<-1;return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{

		cout<<dist[i-1]-dist[i];
	}
}
