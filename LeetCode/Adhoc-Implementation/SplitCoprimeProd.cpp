//https://leetcode.com/problems/split-the-array-to-make-coprime-products/description/
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int mxval = 0;
        for(auto i:nums) mxval = max(mxval, i);
        int spf[mxval + 1];
        for(int i=1;i<mxval + 1;i++) spf[i]=i;
        for(int i=2;i*i<mxval + 1;i++) {
            if(spf[i]==i) {
                for(int j=i*i;j<mxval + 1;j+=i) spf[j]=min(spf[j], i);
            }
        }
        set<int> primes;
        map<int, int> primeOcc;
        for(int i=0;i<nums.size();i++) {
            int ct =nums[i];
            while(ct>1) {
                primeOcc[spf[ct]]=i;
                ct/=spf[ct];
            }
        }
        int nxtPossible=0;
        for(int i=0;i<nums.size() - 1;i++) {
            int ct =nums[i];
            while(ct>1) {
                primes.insert(spf[ct]);
                ct/=spf[ct];
            }
            bool valid=true;
            if(i<nxtPossible) continue;
            for(auto j:primes) {
                if(primeOcc[j]>i) {
                    nxtPossible=max(primeOcc[j], nxtPossible);
                    valid=false;
                }
            }
            if(valid) return i;
        }
        return -1;
    }
};
