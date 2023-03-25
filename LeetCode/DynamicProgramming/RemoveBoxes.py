# https://leetcode.com/problems/remove-boxes/description/
class Solution(object):
    def removeBoxes(self, boxes):
        @cache 
        def recurse(i, j, k):
            if i>j:
                return 0
            ret = (k+1)**2 + recurse(i+1, j, 0)
            inds = [ind for ind in range(i+1, j+1) if boxes[i]==boxes[ind]]
            return max(list(map(lambda x: recurse(i+1, x-1, 0) + recurse(x, j, k+1), inds)) + [ret])
        return recurse(0, len(boxes) - 1, 0)
