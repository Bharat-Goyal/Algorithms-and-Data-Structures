/*input
5
1 2 3 4 5
5 4 3 2 0



*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAX 10000000000
int dp[100001], a[100001], n, b[100001];
vector<int> c;
vector<int> m;int pointer;
bool check(int c1,int c2,int c3,int m1,int m2,int m3)
{
	double ft=(c1 - c2 + 0.0)/(m2 - m1 + 0.0);
	double st=(c1 - c3 + 0.0)/(m3 - m1 + 0.0);
	return ft>=st;
}
void add(int ci, int mi)
{
	c.push_back(ci);m.push_back(mi);
	while(c.size()>=3&&check(c[c.size() - 3], c[c.size() - 2], c[c.size() - 1], m[c.size() - 3], m[c.size() - 2], m[c.size() - 1]))
	{
		c.erase(c.end() - 2);
		m.erase(m.end() - 2);
	}
}
int query(int x)
{
	if(pointer>=c.size())
	{
		pointer=c.size()-1;
	}
	while(pointer<c.size()-1&&m[pointer]*x + c[pointer]>m[pointer+1]*x + c[pointer+1]) pointer++;
	return m[pointer]*x + c[pointer];
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	dp[0]=0;//as the chainsaw is charged initially
	add(dp[0], b[0]);
	pointer=0;
	for(int i=1;i<n;i++)
	{
		dp[i]=query(a[i]);
		if(i!=n-1)
		{
			add(dp[i], b[i]);
		}
	}
	cout<<dp[n-1];
}