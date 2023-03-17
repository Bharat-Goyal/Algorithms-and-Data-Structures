//https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/
#define pii pair<int, int> 
#define mp make_pair
#define f first
#define s second
bool sf(vector<int> a, vector<int> b) {
    return a[1] < b[1];}
class Solution {
public:
    int getOverlap(int *on, int l, int r) {
        int ret=0;
        for(int i=l;i<=r;i++) ret+=on[i];
        return ret;
    }
    void add(int *on, int r, int ct) {
        while(ct>0) {
            // cout<<r<<" ";
            if(!on[r]) {
                on[r]=1;
                ct--;
            }
            r--;
        }
        // cout<<endl;
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
     //dp[i][j]>=duration of every containing task.  
     sort(tasks.begin(), tasks.end(), sf);
     int on[2001] = {0};

     for(auto i:tasks) {
        int l = i[0], r = i[1];
        int req = i[2] - getOverlap(on, l, r); 
        add(on, r, req);
     }
    //  for(int i=1;i<=19;i++) cout<<on[i]<<" ";
     return getOverlap(on, 1, 2000);
    }
};
