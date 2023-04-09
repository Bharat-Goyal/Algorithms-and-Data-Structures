//https://leetcode.com/problems/contains-duplicate-iii/description/
#define pii pair<int, int> 
#define f first
#define s second
#define mp make_pair
class Solution {
    int tree[400001];
    void build(int i, int l, int r) {
        tree[i]=0;
        if(l==r) {
            return;
        }
        int mid=(l+r)>>1;
        build(2*i, l, mid);
        build(2*i+1, mid+1, r);
    }
    void update(int i, int l, int r, int ql) {
        if(r<ql||l>ql) return;
        if(l==r) {
            tree[i] ^=1;return;
        }
        int mid=(l+r)>>1;
        update(2*i, l, mid, ql);
        update(2*i+1, mid+1, r, ql);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    int query(int i, int l, int r, int ql, int qr) {
        if(l>qr||r<ql) return 0;
        if(l>=ql&&r<=qr) {
            return tree[i];}
        int mid=(l+r)>>1;
        return query(2*i, l, mid, ql, qr) + query(2*i+1, mid+1, r, ql, 
qr);
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, 
int valueDiff) {
        vector< pii > seq;
        int n=nums.size();
        build(1, 0, n-1);
        for(int i=0;i<n;i++) {
            seq.push_back(mp(nums[i], i));
        }
        sort(seq.begin(), seq.end());
        int l=0, r=0;
        // multiset<int> inds;
        for(int i=0;i<n;i++) {
            while(r<n && seq[r].f - seq[i].f <= valueDiff) {
                update(1, 0, n-1, seq[r].s);
                r++;
            }
            while(l<r && seq[i].f - seq[l].f > valueDiff) {
                update(1, 0, n-1, seq[l].s);
                l++;
            }
            // cout<<seq[i].s<<" range ="<<seq[i].s - indexDiff<<" to 
"<<seq[i].s + indexDiff<<" = "<<query(1, 0, n-1, seq[i].s - indexDiff, 
seq[i].s + indexDiff)<<"out of"<<tree[1]<<" l="<<l<<" r="<<r<<endl;
            if(query(1, 0, n-1, seq[i].s - indexDiff, seq[i].s + 
indexDiff) > 1) return true;
            // multiset<int>::iterator it = inds.upper_bound(seq[i].s);
            // if(it!=inds.end()) {
            //     if(abs((*it) - seq[i].s) <= indexDiff) {
            //         // cout<<(*it)<<" "<<seq[i].s<<endl;
            //         return true;}
            // }
            // it--;
            // if(it!=inds.begin()) {
            //     it--;
            //     if(abs((*it) - seq[i].s) <= indexDiff) {
            //         // cout<<(*it)<<" "<<seq[i].s<<endl;
            //         return true;}
            // }
        }
        return false;
    }
};//[1,2,3,1], value equal, indexdiff
