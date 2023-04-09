#https://leetcode.com/problems/simplify-path/description/
class Solution:
    def simplifyPath(self, path: str) -> str:
        """
        :type path: str
        :rtype: str
        """
        ls = list(filter(None, path.split("/")))
        ans = []
        for i in ls: 
            if i == "..":
                if len(ans)>=1:
                    ans.pop()
            elif i != "." : 
                ans = ans + ["/" + i]
        if len(ans) == 0:
            ans.append("/")
        return "".join(ans)

