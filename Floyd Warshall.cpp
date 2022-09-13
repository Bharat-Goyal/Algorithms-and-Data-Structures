#include<bits/stdc++.h>
using namespace std;
long int graph[240][240];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    long int n, m;
    cin>>n>>m;
    for(int i=0;i<240;i++)
    {
        for(int j=0;j<240;j++)
        {graph[i][j]=INT_MAX;}
    }
    for(int i=0;i<m;i++)
    {
        long int a, b, c;cin>>a>>b>>c;
        graph[a][b]=min(graph[a][b], c);graph[b][a]=min(graph[b][a], c);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graph[i][k]!=INT_MAX&&graph[k][j]!=INT_MAX&&graph[k][j]+graph[i][k]<graph[i][j])
                {graph[i][j]=graph[i][k]+graph[k][j];}
            }
        }
    }
    long int ans=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            ans=max(graph[i][j], ans);}
            
    }
    cout<<ans;
    return 0;
} 