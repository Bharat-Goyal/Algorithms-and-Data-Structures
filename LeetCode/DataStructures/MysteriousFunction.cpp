//https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/
class Solution {
public:
    int tree[400010], n, arr[100001], ql, ans, qr; 
    void build(int i, int l, int r) {
        if(l==r) {
            tree[i]=arr[l];
            return;
        }
        int mid=(l+r)>>1;
        build(2*i, l, mid);build(2*i+1, mid+1, r);
        tree[i]=(tree[2*i] & tree[2*i+1]);
        //cout<<l<<" "<<r<<":"<< tree[i]<<endl;
    }
    int query(int i, int l, int r) {
        if(l>qr || r<ql) return -1; 
        if(l>=ql&&r<=qr) return tree[i];
        int mid=(l+r)>>1;
        return (query(2*i, l, mid) & query(2*i+1, mid+1, r));
    }
    int closestToTarget(vector<int>& array, int target) {
        n=array.size(); 
        for(int i=n;i>=1;i--) arr[i]=array[i-1];
        int ans=1e7; 
        build(1, 1, n);
        for(int i=1;i<=n;i++) {
            int low=i, high=n;
            ql=i;
            while(low<high) {
                int mid=(low+high)>>1;
                qr=mid;
                int qv = query(1, 1, n);
                if(qv > target) {
                    low=mid+1; 
                }
                else {
                    high=mid; 
                }
            }
            qr = low;
            // cout<<i<<":"<<low<<" "<<query(1, 1, n)<<endl;
            ans=min(ans, abs(target - query(1, 1, n)));
            low--;
            if(low>= i) {
                qr = low;
                ans=min(ans, abs(target - query(1, 1, n)));
            }
        }
        return ans;
    }
};
