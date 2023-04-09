//https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {
public:
    void maxLen(string s, int mid, bool even, int &ret, int &st) {
        int curLen = 0;
        int l, r;
        if(even) {
            l=mid;r = mid+1;
        }
        else {
            l = mid-1;r=mid+1;
            curLen=1;
        }
        while(l>=0 && r<s.size()) {
            if(s[l] == s[r]) {
                curLen+=2;
            }
            else break;
            l--;r++;
        }
        if(curLen > ret) {
            ret = curLen;
            st = l+1;
        }
    }
    string longestPalindrome(string s) {
        int l, len=0;
        for(int i=0;i<s.size();i++) {
            maxLen(s, i, false, len, l);
            maxLen(s, i, true, len, l);    
        }
        return s.substr(l, len);
    }
};
