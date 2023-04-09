//https://leetcode.com/problems/sort-colors/description/
class Solution {
public:
    void fixVal(vector<int>& nums, int n, int &nxt, int val) {
        if(nxt>=n) return;
        for(int i=nxt;i<n;i++) {
            if(nums[i]==val) {
                if(nxt==i) nxt++;
                else swap(nums[i], nums[nxt++]);
                // while(nxt<n && nums[nxt]==val) nxt++;
            }
            // cout<<i<<": "<<nxt<<endl;
            // for(auto j:nums) cout<<j<<" ";cout<<endl<<endl;
            if(nxt==n) return;
        }
    }
    void sortColors(vector<int>& nums) {
        int nxt = 0, n = nums.size();
        fixVal(nums, n, nxt, 0);
        fixVal(nums, n, nxt, 1);
    }
};
