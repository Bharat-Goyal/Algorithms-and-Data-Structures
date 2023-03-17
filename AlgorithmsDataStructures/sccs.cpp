#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adjlist[100001][2];stack<int> s;int n, m, num[100001], vals[100001], cur;bool visited[100001];
int dfs(int i, int ind)
{
    visited[i]=1;int ret=1;
    if(ind==1) num[i]=cur;
    for(auto j:adjlist[i][ind])
    {
        if(!visited[j]) {ret+=dfs(j, ind);}   
    }
    if(ind==0) s.push(i);
    return ret;
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) visited[i]=false;
    for(int i=0;i<m;i++)
    {
        int a, b;cin>>a>>b;adjlist[a][0].push_back(b);adjlist[b][1].push_back(a);
    }
    int garb;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i]) garb=dfs(i, 0);
    }
    for(int i=1;i<=n;i++) visited[i]=false;
    while(!s.empty()){
        int node=s.top();s.pop();
        if(visited[node]) continue;
        vals[cur]=dfs(node, 1);cur++;
    }
    for(int i=1;i<=n;i++)
    {
        if(vals[num[i]]>1) cout<<1<<" ";
        else cout<<"0 ";
    }
}
/*why this works: If we consider each SCC to be a vertex in a new graph, we’ll get a DAG (if its cyclic, then some of the nodes which have been
 taken as separate SCCs will actually be a part of the same SCC). Now, when we conduct the first DFS, we’ll get some vertices which will function 
 as sources (from where the dfs starts and explores the other sccs) and then some components which will function as sinks (where the dfs will end). 
 When the graph is transposed, the sources will become the sinks and vice versa. The SCCs will remain unaffected as the vertices will still be able 
 to reach one another. However, as the edges connecting the different SCCs have been reversed, what was originally used as the source can’t be used 
 to explore the other SCCs. Thus, each dfs will yield an SCC. For the vertices which have now become sources, we’ll see that they won’t be able to 
 explore the other SCCs as those SCCs will already have been explored by that the DFS is conducted from these sources. */ 