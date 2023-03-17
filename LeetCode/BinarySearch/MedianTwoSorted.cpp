//https://leetcode.com/problems/median-of-two-sorted-arrays/description/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m = nums2.size(); 
        if(n>m) return findMedianSortedArrays(nums2, nums1);
        int low=0, high = n;//binary searching for the index of the first guy on the right side. 
        while(low<=high) {
            int mid=(low+high+1)>>1;
            int p1 = mid;
            int p2 = (n+m+1)/2 - p1; 
            int l1 = (p1==0)?INT_MIN:nums1[p1-1];
            int r1 = (p1==n)?INT_MAX:nums1[p1];
            int l2 = (p2==0)?INT_MIN:nums2[p2-1];
            int r2 = (p2==m)?INT_MAX:nums2[p2];
            if(l1<=r2 && l2<=r1) {
                if((n+m)%2==0) {
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
                return max(l1, l2);
            }
            if(l1>r2) {
                high = mid -1; 
            }
            else if(l2>r1) {
                low=mid+1;
            }
        }
        return 9;
    }
};
