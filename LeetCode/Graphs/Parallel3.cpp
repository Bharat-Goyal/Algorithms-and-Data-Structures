//https://leetcode.com/problems/parallel-courses-iii/description/
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> outlist[n+1];
        int indegree[n+1];
        for(int i=1;i<=n;i++) indegree[i]=0;
        time.insert(time.begin(), 0);
        for(auto i:relations) {
            outlist[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        int st[n+1];
        for(int i=1;i<=n;i++) {
            st[i] = 0;
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()) {
            int cur=q.front();q.pop();
            for(auto j:outlist[cur]) {
                indegree[j]--;
                st[j]=max(st[j], time[cur] + st[cur]);
                if(indegree[j]==0) q.push(j);
            }
        }
        int ret=0;
        for(int i=1;i<=n;i++) {
            ret=max(ret, st[i] + time[i]);
        }
        return ret;
    }
};
