//https://leetcode.com/problems/minimum-window-substring/description/
class Solution {
public:
    int conv(char a) {
        if(a>='a' && a<='z') return a - 'a';
        return (a-'A') + 26;
    }
    string minWindow(string s, string t) {
        int n = s.length(); 
        int cur[52]= {0};
        int req[52] = {0};
        for(auto i:t) {
            req[conv(i)]++;
        }
        int prevcheck=0;
        int l=1, r=1;
        while(prevcheck<52 && r<=n) {
            cur[conv(s[r-1])]++;
            while(prevcheck<52 && req[prevcheck] <= cur[prevcheck]) {
                prevcheck++;
            }
            if(prevcheck < 52) r++;
        }
        if(r>n) return "";
        int bestlen=r-l+1, st=l;
        prevcheck = conv(s[l-1]);l++;
        cur[prevcheck]--;
        while(r<=n) {
            while(prevcheck!=-1 && r<=n) {
                if(req[prevcheck] <= cur[prevcheck]) {
                    prevcheck = -1;break;
                }
                r++;
                if(r>n) {break;}
                cur[conv(s[r-1])]++;
            }
            if(r<=n && r-l+1 < bestlen) {
                bestlen = r-l+1;
                st=l;
            }
            prevcheck = conv(s[l-1]);l++;
            if(l>n) break;
            cur[prevcheck]--;
            cout<<l<<" "<<r<<endl;
        }
        if(st==-1) return "";
        return s.substr(st-1, bestlen);
    }
};
