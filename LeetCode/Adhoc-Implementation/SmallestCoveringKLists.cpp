//https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
#define pii pair<int, int> 
#define f first
#define s second
#define mp make_pair
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector< pii > comb;
        int k = nums.size();
        for(int i=0;i<nums.size();i++) {
            for(auto j:nums[i]) comb.push_back(mp(j, i));
        }
        int n=comb.size();
        sort(comb.begin(), comb.end());
        int l=0, r=0;
        map<int, int> occ;
        int l1=comb[0].f, r1=comb.back().f;
        int ans = r1-l1+1;
        while(r<n || occ.size()==k) {
            while(r<n && occ.size() < k) {
                if(occ.count(comb[r].s)==0) occ[comb[r].s] = 0;
                occ[comb[r].s]++;
                r++;
            }
            if(occ.size()<k) break;
            if(ans>comb[r-1].f-comb[l].f+1) {
                l1 = comb[l].f;
                r1 = comb[r-1].f;
                ans=r1-l1+1;
            }
            occ[comb[l].s]--;
            if(occ[comb[l].s] == 0){
                occ.erase(comb[l].s);
            }
            l++;
        }
        vector<int> ret;ret.push_back(l1);ret.push_back(r1);
        return ret;
    }
};
