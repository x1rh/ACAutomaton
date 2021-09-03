# 题目
`https://leetcode-cn.com/problems/corporate-flight-bookings/`


# 思路
## 解法1：线段树, 区间更新（lazy标记）, 区间查询（实际退化为一个点）  

复杂度：
- 时间复杂度：
  - 整体update: O(nlogn)  
  - 整体query: O(nlogn)
- 空间复杂度
  - O(4n)

细节：
- sum的更新是+=
- add的更新也是+=
- down的时候要求add[rt]>0
- 爆int

WA了7发，吐了。最后几发WA在了leetcode的运行机制上（我把sum、add、up、down、update写在Solution外面）。初始化一次Solution，然后开线程运行？？？好像也不对，我memset了也不行，写进Solution里解决了。  

```cpp
class Solution {

public:
long long sum[4*20000+10];
long long add[4*20000+10];

void up(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void down(int rt, int len){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt] * static_cast<long long>(len - (len>>1));
        sum[rt<<1|1] += add[rt] * static_cast<long long>(len>>1);
        add[rt] = 0;
    }
}

void update(int rt, int l, int r, int x, int y, int v){
    if(x<=l && r<=y){
        sum[rt] += static_cast<long long>(v) * static_cast<long long>(r-l+1);
        add[rt] += v;
    }
    else{
        down(rt, r-l+1);
        int mid = (l+r)>>1;
        if(x<=mid) update(rt<<1, l, mid, x, y, v);
        if(mid<y) update(rt<<1|1, mid+1, r, x, y, v);
        up(rt);
    }
}

long long query(int rt, int l, int r, int x, int y){
    if(x<=l && r<=y){
        return sum[rt];
    }
    else{
        int mid = (l+r)>>1;
        long long retval = 0;
        down(rt, r-l+1);
        if(x<=mid) retval = query(rt<<1, l, mid, x, y);
        if(mid<y) retval += query(rt<<1|1, mid+1, r, x, y);
        up(rt);
        return retval;
    }
}


public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        memset(sum, 0, size(sum));
        memset(add, 0, size(add));
        for(auto &x : bookings){
            int l = x[0];
            int r = x[1];
            int v = x[2];
            update(1, 1, n, l, r, v);
        }

        vector<int> ans;
        for(int i=1; i<=n; ++i){
            long long retval = query(1, 1, n, i, i);
            ans.push_back(static_cast<int>(retval));
        }
        return ans;

    }
};
```


## 解法2： 差分

数组A的差分数组B的定义为：第i个数`B[i]=A[i]-A[i-1]`，举例说明如下：  
对于数组`[1, 2, 2, 4]`其对应的差分数组为`[1, 1, 0, 2]`。

差分数组的性质：
1. 对原数组A的区间`[l, r]`同时增加一个值x，表现为差分数组`B[l]_curr = B[l]_pre + x`， `B[r+1]_curr = B[r+1]_pre - x`
2. 对差分数组求前缀和可以得到原数组A


利用这些性质，不难写出如下解:
```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+1);
        for(auto &x : bookings){
            ans[x[0]-1] += x[2];
            ans[x[1]] -= x[2];
        }
        for(int i=1; i<n; ++i){
            ans[i] += ans[i-1];
        }
        ans.pop_back();
        return ans;
    }
};
```