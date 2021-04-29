#
# 寻找最后的山峰
# @param a int整型一维数组 
# @return int整型
#
class Solution:
    def solve(self , a ):
        idx = -1
        can = list()
        for i, el in enumerate(a):
            if i==0 and el>=a[i+1]:
                can.append((el, i))
            elif i==len(a)-1 and el>=a[i-1]:
                can.append((el, i))
            elif a[i-1] <= el and el >= a[i+1]:
                can.append((el, i))
        
        return can[-1][1]