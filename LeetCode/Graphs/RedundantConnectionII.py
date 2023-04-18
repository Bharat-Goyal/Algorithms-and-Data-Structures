#https://leetcode.com/problems/redundant-connection-ii/description/
class Solution:
    def dfs(self, cur, p, cyc):
        cyc[cur] = 1
        for nxt in p[cur]:
            if cyc[nxt] == 0:
                continue
            if cyc[nxt] == 1: 
                return nxt
            temp = self.dfs(nxt, p, cyc)
            if temp == 0:#cycle found and marked, end function
                cyc[cur] = 0
                return 0
            if temp != -1:
                if temp != cur: 
                    return temp
                return 0
        cyc[cur] = 0
        return -1
        
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> 
List[int]:
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        n=len(edges)
        indeg = [0]*(n+1)
        p = []
        for i in range(n+1):
            p.append([])
        cyc = [-1]*(n+1)
        in2 = -1
        for i in edges: 
            indeg[i[1]] += 1
            if indeg[i[1]] > 1: 
                in2 = i[1]
            p[i[0]].append(i[1])
        for i in range(1, n+1):
            if self.dfs(i, p, cyc) ==0:
                break
        ret = []
        for i in edges: 
            if in2 != -1 and in2 == i[1] and cyc[i[0]] == 1:
                return i 
            if cyc[i[0]]==1 and cyc[i[1]]==1:
                ret = i
        if len(ret) > 0:
            return ret
        for i in edges: 
            indeg[i[1]] -= 1
            if indeg[in2] == 0:
                return i
        return []
