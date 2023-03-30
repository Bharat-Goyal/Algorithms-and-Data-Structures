#https://leetcode.com/problems/insert-delete-getrandom-o1/description/
class RandomizedSet(object):
    def __init__(self):
        self.d = {}
        self.ls = []

    def insert(self, val):
        """
        :type val: int
        :rtype: bool
        """
        temp = val in self.d
        # print(f"{val} bool: {temp}")
        if val in self.d: 
            return False 
        self.ls = self.ls + [val]
        self.d[val] = len(self.ls) - 1
        return True

    def remove(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val not in self.d: 
            return False 
        self.d[self.ls[-1]] = self.d[val]
        self.ls[self.d[val]], self.ls[-1] = self.ls[-1], self.ls[self.d[val]]
        self.d.pop(val)
        self.ls = self.ls[0:-1]
        return True

    def getRandom(self):
        """
        :rtype: int
        """
        return self.ls[random.randint(0, len(self.ls) - 1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
