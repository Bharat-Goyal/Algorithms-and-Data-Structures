//https://leetcode.com/problems/prefix-and-suffix-search/description/
#define pii pair<string, string>
#define mp make_pair
class WordFilter {
public:
    unordered_map<string, int> ans;
    
    WordFilter(vector<string>& words) {
        ans.clear();
        if(words.empty()) return;
        int ind=0;
        for(auto st:words) {
            for(int i=1;i<=st.length();i++) {
                for(int j=1;j<=st.length();j++) {
                    ans[st.substr(0, i) + " " + st.substr(st.length() - 
j)]= ind;
                }
            }
            ind++;
        }
    }
    
    int f(string curpref, string cursuff) {   
        string query = curpref + " " + cursuff;
        if(ans.count(query)==0) return -1;
        return ans[query];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
