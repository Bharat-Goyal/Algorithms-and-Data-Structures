#include<bits/stdc++.h>
using namespace std;//whenever you conduct a dfs, you're actually creating a tree, reason being that the nodes which have been visited won't be visited again and, thus, the graph of the dfs will have just one way of reaching the current node and will, hence, be a tree. 
vector<int> adjlist[1000];vector<bool> aps(1000, false);int low[1000], disc[1000], t, parent[1000], root;//no need for visited, initialise parent to -1. if(parent[x]==-1&&x!=root) 
void dfs(int cur)
{
	disc[cur]=low[cur]=t;//the lowest node that it can reach will be itself. This can be updated. We can't set this value disc[parent[cur]] because we want to see the first node, aside fromt the parent, that this node is connected to.  
	int child=0;
	for(int i=0;i<(int)adjlist[cur].size();i++)
	{
		int next=adjlist[cur][i];
		if(parent[next]==-1&&next!=root)//if unexplored, explore the current vertex and set the parent value
		{
			child++;
			parent[next]=cur;t++;dfs(next);//t has to be increased before you explore the next vertex
			low[cur]=min(low[cur], low[next]);//its low next as we can go any number of edges downwards but just one upwards, therefore, go to next and then the one with earliest discovery t
			if(disc[cur]<=low[next]&&cur!=root)
			{
				aps[cur]=true;
			}
			else if(cur==root&&child>1)//if after the dfs has been completed, there still exists some unvisited nodes, then they will be disconnected in the absence of the root(can't be reached from the children).
			{
				aps[cur]=true;
			}
		}
		else if(parent[cur]!=next)//if parent of this node isn't next itself, and visited next, then low[cur], node with lowest discovery t that cur reach, can be updated
		{
			low[cur]=min(low[cur], disc[next]);//it isn't min(low[cur], low[next]) as you can't reach the lowest value of next without having to go to next first. Thus, it won't be one backedge, but multiple ones. In the case of a child, we can go through multiple edges as there'll just be one BACKedge.
		}
	}
}
int main()
{
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a, b;cin>>a>>b;
		adjlist[a].push_back(b);adjlist[b].push_back(a);
	}
	for(int i=0;i<=n;i++)
	{
		parent[i]=-1;
	}
	root=1;//it can be taken in the input too. 
	t=0;
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		if(aps[i]) cout<<i<<" ";
	}
}
