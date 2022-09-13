#include<bits/stdc++.h>
#define pii pair< pair<int, int>, int>
#define f first
#define s second
using namespace std;
pii edges[300];//this is the elogv algorithm
int parent[300];int rank[300];
int find(int x)
{
	if(parent[x]!=x)
	{parent[x]=find(parent[x]);
	}
	return parent[x];
}
void u(int x, int y)
{
	if(rank[x]>rank[y]) parent[y]=x;
	else if(rank[y]>rank[x]) parent[x]=y;
	else
	{
		parent[y]=x;rank[x]++;
	}
}
bool sf(pii a, pii b)
{
	return a.s<=b.s;
}
int main()
{
	int n, m;
	cin>>n>>m;
	for(int i=0;i<300;i++)
	{
		parent[i]=i;rank[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		cin>>edges[i].f.f>>edges[i].f.s>>edges[i].s;
	}
	sort(edges, edges + m, sf);
	int counter=0;
	for(int i=0;i<m&&counter<n;i++)
	{
		int x=find(edges[i].f.f), y=find(edges[i].f.s);
		if(x==y) continue;
		else
		{counter++;u(x, y);
		}
	}
}
