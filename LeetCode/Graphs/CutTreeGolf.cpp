//https://leetcode.com/problems/cut-off-trees-for-golf-event/description/
#define pii pair<int, int> 
#define f first
#define s second
#define mp make_pair
class Solution {
    int dist[2500];
public:
    int exp(pii src, pii tar, vector<vector<int>>& forest) {
        int n=forest.size(), m=forest[0].size();
        queue<pii> q; 
        q.push(src);
        for(int i=0;i<n*m;i++) dist[i] = -1;
        dist[src.f*m + src.s]=0;
        int arr[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while(!q.empty()) {
            pii cur = q.front();q.pop();
            for(int i=0;i<4;i++) {
                pii nxt = {cur.f + arr[i][0], cur.s+arr[i][1]};
                if(nxt.f >= 0 && nxt.f <n && nxt.s >=0 && nxt.s < m 
                   && forest[nxt.f][nxt.s] > 0 && dist[nxt.f*m + nxt.s] == 
-1)
                {
                    dist[nxt.f*m + nxt.s] = dist[cur.f*m + cur.s] + 1;
                    q.push(nxt);
                }
                if(dist[tar.f*m + tar.s] != -1) break;
            }       
        }
        return dist[tar.f*m + tar.s];
    }
    int cutOffTree(vector<vector<int>>& forest) {
        map< int, pii > vals; 
        for(int i=0;i<forest.size();i++) {
            for(int j=0;j<forest[0].size();j++) {
                if(forest[i][j]<=1) continue;
                vals[forest[i][j]] = mp(i, j);
            }
        }
        int ans=0;
        pii src = {0, 0};
        for(auto i:vals) {
            int temp = exp(src, i.s, forest);
            if(temp==-1) return -1;
            ans+=temp;
            src = i.s;
        }
        return ans;
    }
};
