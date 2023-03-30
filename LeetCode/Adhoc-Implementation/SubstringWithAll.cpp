//https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //Find all occurrences of every word. 
        int n=s.length();
        int occs[n];
        for(int i=0;i<n;i++) occs[i]=-1;
        int slen = words[0].length();
        for(int i=0;i<=n - slen;i++) {
            for(int j=0;j<words.size();j++) {
                if(words[j].compare(s.substr(i, slen))==0) {
                    occs[i] = (j);}
            }
        }
        vector<int> ret;
        for(int st=0;st<slen;st++) {
            map<string, int> freq;
            map<string, int> over;
            for(auto j:words) {
                if(freq.count(j) == 0) freq[j] = 0;
                freq[j]++;
            }
            int ll = st;
            for(int i=st;i+slen-1<n;i+=slen) {
                string cursub = s.substr(i, slen);
                if(occs[i]!= -1) {
                    if(freq.count(cursub)){
                        freq[cursub]--;
                        if(freq[cursub] == 0) freq.erase(cursub);
                    }
                    else {
                        if(over.count(cursub) == 0) over[cursub] = 0;
                        over[cursub] ++;
                    }
                }
                if((i-ll)/slen + 1 > words.size()) {
                    if(occs[ll] != -1) 
                    {
                        string prevsub = s.substr(ll, slen);
                        if(over.count(prevsub)) {
                            over[prevsub]--;
                            if(over[prevsub] == 0) over.erase(prevsub);
                        }
                        else {
                            if(freq.count(prevsub) == 0) freq[prevsub] = 0;
                            freq[prevsub]++;
                        }
                    }
                    ll+=slen;
                }
                if(freq.size()==0) ret.push_back(ll);
                if(st==0) {
                    // cout<<ll<<" "<<i<<endl;
                    // for(auto j:freq) cout<<j.first<<" "<<j.second<<endl;
                    // cout<<"over\n";
                    // for(auto j:over) cout<<j.first<<" "<<j.second<<endl;
                    // cout<<endl;
                }
            }
        }
        return ret;
    }
};
//wordgoodgoodgoodbestword
//good (1, 3), word 0, best 2
