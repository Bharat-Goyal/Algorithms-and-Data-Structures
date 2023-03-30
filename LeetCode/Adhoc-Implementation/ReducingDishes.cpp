//https://leetcode.com/problems/reducing-dishes/description/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int ret=max(0, satisfaction[n-1]);
        for(int i=n-2;i>=0;i--) {
            satisfaction[i] += satisfaction[i+1];
        }
        for(int i=n-2;i>=0;i--) {
            satisfaction[i] += satisfaction[i+1];
            ret=max(ret, satisfaction[i]);
        }
        return ret;
    }
};
