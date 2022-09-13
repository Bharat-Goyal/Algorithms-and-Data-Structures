/*input
4
2 1 1 1
*/
//Problem: partition given array into segments (no element left out, all segments contiguous) such that the means of the 
//segments are non decreasing.
//Increasing means, IOITC 2018 TST 3 P1
#include<bits/stdc++.h>
using namespace std;
const int N=1e5 + 100;
const int mod=1e9 + 7;
#define int long long
const int inf=1e18;
#define pii pair<int, int>
#define x first
#define y second 
#define s second
#define f first
#define mp make_pair
#define FOR(i, n) for(int i=1;i<=n;i++)
#define TRACE(x) cerr << #x << " = " << x << endl 
//Trace prints the name of the variable and the value.
int n, arr[N];pii points[N];
double dotp(pii a, pii b)
{
    double ret=(a.x-b.x);
    double denom=pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
    ret/=denom;return ret;
}
bool sf(pii a, pii b)
{
    return dotp(a, points[1])>dotp(b, points[1]);
}
int paral(pii a, pii b, pii c)
{
    int val=(b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);return val;
}
stack<int> R;vector< pii > ranges;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;arr[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];arr[i]+=arr[i-1];points[i]=mp(i, arr[i]);
    }
    sort(points+2, points+n+1, sf);points[0]=mp(0, 0);
    stack< pii > st;st.push(points[0]);
    for(int i=1;i<=n;i++)
    {
        st.push(points[i]);
        bool check=false;
        while(st.size()>=3)
        {
            pii pl, pm, pf;pl=st.top();st.pop();pm=st.top();st.pop();pf=st.top();st.pop();
            int temp=paral(pf, pm, pl);st.push(pf);
            if(temp>=0) 
            {
                st.push(pm);check=1;
            }
            st.push(pl);
            if(check) break;
        }
        if(points[i].y==arr[n]) break;
    }//convex hull code ends here 
    while(!st.empty())
    {
        if(st.top().x==0) break;
        R.push(st.top().x);
        st.pop();
    }
    int nl=1;
    while(!R.empty())
    {
        ranges.push_back(mp(nl, R.top()));nl=R.top()+1;R.pop();
    }
    int l=ranges.back().f, r=ranges.back().s;double m=(arr[r] - arr[l-1] + 0.0)/(r-l+1.0);
    int ans=ranges.size();
    for(int i=ranges.size()-2;i>=0;i--)
    {
        int nl=ranges[i].f, nr=ranges[i].s;
        double nm=(arr[nr] - arr[nl-1] + 0.0)/(nr-nl+1.0);
        if(nm==m) l=nl;
        else break;
        ans--;
    }
    cout<<ans<<endl;
    for(auto i:ranges)
    {
        if(i.f==l)
        {
            cout<<l<<" "<<n;break;
        }
        cout<<i.f<<" "<<i.s<<endl;
    }
}