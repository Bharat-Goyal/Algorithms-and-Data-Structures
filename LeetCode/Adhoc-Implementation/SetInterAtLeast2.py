#https://leetcode.com/problems/set-intersection-size-at-least-two/description/
class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        ordered = sorted(intervals, key = lambda x: x[1])
        ls = [ordered[0][1] - 1, ordered[0][1] ]
        for i in range(1, len(ordered)):
            if ls[-2]>= ordered[i][0]:
                continue 
            elif ls[-1] >= ordered[i][0]:
                if ls[-1] == ordered[i][1]:
                    ls = ls + [ordered[i][1] - 1]
                    ls[-1], ls[-2] = ls[-2], ls[-1]
                else: 
                    ls = ls + [ordered[i][1]]
            else: 
                ls = ls + [ordered[i][1]-1, ordered[i][1]]
        # print(ls)
        return len(ls)
                
