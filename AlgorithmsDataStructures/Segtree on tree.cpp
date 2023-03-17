/*input
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4

*/
//cf 255C propagating tree
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, tree[800001];int start[200001], fin[200001], arr[200001];
vector<int> adjlist[200001];int t, depth[200001], ql, qr, par, val;
void dfs(int i)
{
	start[i]=t++;
	for(int j=0;j<adjlist[i].size();j++)
	{
		int nxt=adjlist[i][j];
		if(start[nxt]!=-1) continue;
		depth[nxt]=(depth[i]^1);
		dfs(nxt);
	}
	fin[i]=t-1;
}
void build(int i, int l, int r)
{
	tree[i]=0;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)/2;
	build(2*i, l, mid);build(2*i+1, mid+1, r);
}
void update(int i, int l, int r)
{
	if(l!=r)
	{
		tree[2*i]+=tree[i];tree[2*i+1]+=tree[i];tree[i]=0;
	}
	if(l>qr||r<ql) return;
	if(l>=ql&&r<=qr)
	{
		if(par==1)
		{
			tree[i]-=val;
		}
		else tree[i]+=val;
		return;
	}
	int mid=(l+r)>>1;
	update(2*i, l, mid);update(2*i+1, mid+1, r);
}
int query(int i, int l, int r)
{
	if(l>ql||r<ql) return 0;
	if(l!=r)
	{
		tree[2*i]+=tree[i];tree[2*i+1]+=tree[i];tree[i]=0;
	}
	if(l==ql&&r==ql)
	{
		return tree[i];
	}
	int mid=(l+r)>>1;
	return query(2*i, l, mid) + query(2*i+1, mid+1, r);	
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;t=1;
	for(int i=1;i<=n;i++) cin>>arr[i];
	for(int i=1;i<n;i++)
	{
		int u, v;cin>>u>>v;adjlist[u].push_back(v);adjlist[v].push_back(u);
		start[i]=-1;
	}
	start[n]=-1;depth[1]=0;
	dfs(1);
	build(1, 1, n);
	while(m--)
	{
		cin>>t>>ql;
		if(t==1)
		{
			cin>>val;qr=fin[ql];par=depth[ql];ql=start[ql];
			update(1, 1, n);
		}
		else
		{
			bool check;int del=arr[ql];
			if(depth[ql]==1) check=1;
			else check=0;
			ql=start[ql];
			if(check)
			{
				cout<<del-query(1, 1, n)<<endl;
			}
			else cout<<del+query(1, 1, n)<<endl;
		}
	}
}