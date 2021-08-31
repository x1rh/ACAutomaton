# 题目
`https://leetcode-cn.com/problems/shuffle-an-array/`


# 思路

解法1：使用python的random.shuffle()
```python
class Solution:

    def __init__(self, nums: List[int]):
        self.L = nums
        self.backup = list(nums)

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.backup


    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        random.shuffle(self.L)
        return self.L

```


解法2： 暴力
如何保证洗牌算法的正确性？  
答：发n次牌，每次发牌拿到任何一张牌的概率都为1/n， 证明如下：  

第k次发牌拿到特定牌x的概率:  
`(n-1)/(n)  *  (n-2)/(n-1) * ... * (n-k)/(n-k+1) * (1)/(n-k) = 1/n`  

代码实现：
每次从数组L中随机取出一个数放入ans中，并把这个数从L中删除（保证每次拿到牌的概率都是1/len，len为剩余的牌的个数，是不是觉得奇怪了。其实上面的是从整体上说每次拿到牌
的概率为1/n，而这里是单独每次）
```python
class Solution:
    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        for i in range(len(self.array)):
            swap_idx = random.randrange(i, len(self.array))
            self.array[i], self.array[swap_idx] = self.array[swap_idx], self.array[i]
        return self.array
```


解法3：  Fisher-Yates 洗牌算法 

使用swap并利用性质，将时间复杂度降到O(n)，既然一次洗牌，第i次拿到牌x的概率和第j次拿到牌y的概率相同，那么交互也不破坏性质  

也可以理解为从后面swap出的数，相当于每次确定一个数，同上面的暴力一致。  

```python
class Solution:
    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        for i in range(len(self.array)):
            swap_idx = random.randrange(i, len(self.array))
            self.array[i], self.array[swap_idx] = self.array[swap_idx], self.array[i]
        return self.array
```