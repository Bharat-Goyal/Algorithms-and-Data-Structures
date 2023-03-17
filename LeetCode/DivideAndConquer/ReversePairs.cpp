//https://leetcode.com/problems/reverse-pairs/description/
class Solution {
public:
    int merge(vector<int> &arr, int l1, int r1, int l2, int r2) {
        int ret=0;
        int i1=r1, i2=r2;
        while(i1>=l1) {
            while(i2>=l2 && ( (long long)arr[i2]>= (long long)arr[i1] - (long long)arr[i2])) {
                i2--;
            }
            ret+= (i2 -l2 + 1);
            i1--;
        }
        vector<int> temp;
        i1=l1; i2=l2;
        while(i1<=r1 && i2<=r2) {
            if(arr[i1]<arr[i2]) {
                temp.push_back(arr[i1++]);
            }
            else {
                temp.push_back(arr[i2++]);
            }
        }
        while(i1<=r1) temp.push_back(arr[i1++]);
        while(i2<=r2) temp.push_back(arr[i2++]);
        for(int i=0;i<temp.size();i++) {
            arr[l1+i]=temp[i];
        }
        return ret;
    } 
    int recurse(vector<int>& arr, int l, int r) {
        if(l==r) {
            return 0;
        }
        int mid=(l+r)>>1;
        int ret = recurse(arr, l, mid) + recurse(arr, mid+1, r);
        ret+=merge(arr, l, mid, mid+1, r);
        return ret;
    }
    int reversePairs(vector<int>& nums) {
        return recurse(nums, 0, nums.size()-1);
    }
};
