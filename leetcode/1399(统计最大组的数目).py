#
# 统计区间[1, n]每个数各个数位的和，
# 并且将和相同的数放在一个数组中，问的是具有最长长度的数组一共有多少个
#


class Solution:
    def countLargestGroup(self, n: int) -> int:
        ans = dict()
        for i in range(1, n+1):
            s = str(i)
            tot = 0
            for d in s:
                tot += int(d)
            
            if ans.get(tot, None):
                ans[tot].append(i)
            else:
                ans[tot] = [i]
        
        res = sorted(ans.items(), key=lambda x:len(x[1]))

        target_len = len(res[-1][1])

        ret = 0
        for k, v in res:
            # print(k, v)
            if len(v) == target_len:
                ret += 1
        
        return ret
