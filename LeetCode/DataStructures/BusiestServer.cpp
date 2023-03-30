//https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/description/
#define pii pair<int, int> 
#define f first
#define s second
#define mp make_pair
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pii, vector<pii>, greater<pii> > busyServers;//first value is the time of freeing
        priority_queue<int, vector<int>, greater<int>> availableServers;//add k to the indices to fix the order. 
        int ct[k];
        for(int i=0;i<k;i++) {ct[i]=0;availableServers.push(i);}
        for(int i=0;i<arrival.size();i++) {
            while(!busyServers.empty() && busyServers.top().f <= arrival[i]) {
                int serv = busyServers.top().s;busyServers.pop();
                int diff = i - i%k;
                availableServers.push(serv + diff);
            }
            if(availableServers.empty()) continue; 
            while(availableServers.top() < i) {
                int serv = availableServers.top();
                availableServers.pop();
                availableServers.push(serv+k);
            }
            int serv = availableServers.top();
            availableServers.pop();
            ct[serv%k]++;
            busyServers.push(mp(arrival[i] + load[i], serv%k));
        }
        int mval = 0;
        for(int i=0;i<k;i++) mval=max(mval, ct[i]);
        vector<int> ret;
        for(int i=0;i<k;i++) {
            if(ct[i]==mval) ret.push_back(i);
        }
        return ret;
    }
};
/*
0:6, 1
1:7, 2
2:13, 1
*/
