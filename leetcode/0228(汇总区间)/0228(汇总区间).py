class Solution:
    '''
    将连续的数字合并成闭区间，注意处理边界即可
    '''
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if len(nums) == 0:
            return list()
        idx = 1
        fr = 0

        ans = list()
        while idx < len(nums):
            if nums[idx] == nums[idx-1] + 1:
                pass
            else:
                if fr != idx-1:
                    ans.append(f'{nums[fr]}->{nums[idx-1]}')
                else:
                    ans.append(f'{nums[fr]}')
                fr = idx
            idx += 1
        
        if fr != len(nums):
            if fr != len(nums)-1:
                ans.append(f'{nums[fr]}->{nums[len(nums)-1]}')
            else:
                ans.append(f'{nums[fr]}')
        return ans