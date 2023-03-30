//https://leetcode.com/problems/shortest-palindrome/description/
class Solution {
public:
    string shortestPalindrome(string temp) {
      int P[temp.size()*2 + 1], ans;string s;
    	for(int i=0;i<temp.size();i++)
    	{
    		s+="#";s+=temp[i];
    	}
    	s+="#";int C=-1, R=-1;ans=0;
    	for(int i=0;i<s.size();i++)
    	{
				P[i]=0;
    		if(i<R)
    		{
					P[i] = R-i+1;
					if(2*C - i >= 0) P[i]=min(P[i], P[2*C-i]);
    		}
    		while(P[i]+1 + i<s.size()&&i - P[i] - 1>=0&&s[P[i]+1+i]==s[i - P[i] - 1])
    		{
    			P[i]++;
    		}
    		if(i+P[i]-1>R)
    		{
    			C=i;R=i+P[i]-1;
    		}
        if( i - P[i] != 0 || P[i]<0) continue;
    		if(s[i]=='#') ans=max(ans, P[i] + (P[i]&(1)) );
    		else ans=max(ans, P[i] - (P[i]&(1)) + 1);
    	}
      string ret;
			for(int i=ans;i<temp.size();i++) ret+=temp[i];
			if(ret.length() > 1) reverse(ret.begin(), ret.end());
			ret += temp;
			return ret;
    }
};
