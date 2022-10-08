'''
模拟即可，因为i累加会迅速消耗memory
'''

class Solution:
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        idx = 1
        while memory1>=idx or memory2>=idx:
            if memory1 >= memory2:
                memory1 -= idx
            else:
                memory2 -= idx
            idx += 1
        return [idx, memory1, memory2]
            
            