# 题目
`https://leetcode-cn.com/problems/two-sum/`


# 思路

## 解法1. 排序（记忆原来的位置） + 二分 + 注意遍历的细节 

```cpp
class Solution {
public:
    struct Node{
        int x, i;
        Node():x(0), i(0){}
        Node(int x, int i):x(x), i(i){}
        bool operator<(const Node &rhs)const{
            return this->x < rhs.x;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<Node> vec(nums.size());
        for(int i=0; i<nums.size(); ++i){
            vec[i].x = nums[i];
            vec[i].i = i;
        }
        sort(vec.begin(), vec.end());
        
        for(int i=0; i<vec.size()-1; ++i){
            auto it = lower_bound(vec.begin()+i+1, vec.end(), Node(target-vec[i].x, 0)) - vec.begin();
            if(it!=vec.size() && vec[it].x==target-vec[i].x){
                ans.push_back(vec[i].i);
                ans.push_back(vec[it].i);
                return ans;
            }
        }
        return ans;
    }
};
```

注意 `lower_bound` 中 `cmp` 的用法
```cpp
class Solution {
public:
    static bool cmp(const pair<int, int> pii, int key){
        return pii.first < key;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; ++i){
            v[i].first = nums[i];
            v[i].second = i;
        }


        sort(v.begin(), v.end());

        for(int i=0; i<n-1; ++i){
            auto it = lower_bound(v.begin()+i+1, v.end(), target-v[i].first, cmp);
            if( (it!=v.end()) && (it->first == (target-v[i].first))) {
                return {v[i].second, it->second};
            }

        }
        return {-1, -1};
    }
};

```



## 解法2. 哈希表
时间复杂度 O(n),  空间复杂度 O(n)
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            auto it = ump.find(target-nums[i]);
            if((it!=ump.end()) && (it->first == (target-nums[i]))){
                return {it->second, i};
            }
            else{
                ump[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};

```


Go版
```Go
func twoSum(nums []int, target int) []int {
    mp := map[int]int{}

    for i, x := range nums {
        v, ok := mp[target-x]
        if ok {
            return []int{v, i}
        } else {
            mp[x] = i
        }
    }

    return []int{-1, -1}
}
```