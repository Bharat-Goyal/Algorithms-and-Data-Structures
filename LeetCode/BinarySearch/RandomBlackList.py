#https://leetcode.com/problems/random-pick-with-blacklist/description/
class Solution:
    def __init__(self, n: int, blacklist: List[int]):
        self.blacklist = sorted(blacklist)
        self.n = n
    def pick(self) -> int:
        ind = random.randint(0, self.n - len(self.blacklist)-1)
        if len(self.blacklist) == 0 or ind < self.blacklist[0]:
            return ind
        if ind>self.blacklist[-1]:
            return ind + len(self.blacklist)
        low, high = 0, len(self.blacklist)-1
        while low<high:
            # print(f"{low} {high}")
            mid=(low+high+1)//2 
            if self.blacklist[mid] <= ind + mid: 
                low = mid
            else:
                high = mid-1
        return ind + low+1

# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()
