/*input
abababa
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int P[100001], ans;string temp, s;
signed main()
{
	cin>>temp;
	for(int i=0;i<temp.size();i++)
	{
		s+="#";s+=temp[i];
	}
	s+="#";int C=-1, R=-1;ans=0;
	for(int i=0;i<s.size();i++)
	{
		if(i<R)
		{
			P[i]=min(R-i+1, P[2*C-i]);

		}
		while(P[i]+1 + i<s.size()&&i - P[i] - 1>=0&&s[P[i]+1+i]==s[i - P[i] - 1])
		{
			P[i]++;
		}
		if(i+P[i]-1>R)
		{
			C=i;R=i+P[i]-1;
		}
		if(s[i]=='#') ans=max(ans, 2*P[i]-1 - (2*P[i]-1)/2 + 1);
		else ans=max(ans, 2*P[i]-1 - (2*P[i]-1)/2);
	}
	cout<<ans;

}