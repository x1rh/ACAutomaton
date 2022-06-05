# 1. cmp、greater、less
### 1.1 优先队列/堆
- 小顶堆：`priority_queue<T, vector<T>, greater<T>>`
- 大顶堆：`priority_queue<T, vector<T>, less<T>>`

### 1.2 实现cmp的多种姿势


# 2. function
### 2.1 利用function实现dfs，避免过多参数重新声明
```cpp
function<void(int, vector<int>, int)> dfs = [&](int si, vector<int> left, int cnt){
    if(si >= special.size()){
        for(int i=0;  i<left.size(); ++i){
            if(left[i] != 0){
                cnt += left[i] * price[i];
            }
        }
        if(cnt < ans){
            ans = cnt;
        }
        return ;
    }
    else{
        for(int i=0; ; ++i){
            
            if(i==0){
                dfs(si+1, left, cnt);
            }
            else{
                vector<int> backup = left;
                vector<int> nv = special[si];
                for(int j=0; j<nv.size()-1; ++j){
                    nv[j] *= i;
                    if(nv[j] > left[j]){
                        return;
                    }
                    else{
                        left[j] -= nv[j];
                    }
                }
                dfs(si+1, left, cnt+nv.back()*i);
                left = backup;
            }
        }
    }
};

```
### 2.2 function + pair 实现排序
```cpp
vector<pair<int, char>> arr = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
sort(arr.begin(), arr.end(), [](const pair<int, char> & p1, const pair<int, char> & p2) {
    return p1.first > p2.first;
});
```
# 3. unordered_map 和 unordered_set

总所周知，`unordered_map`才是cpp中的`hashmap`，是真正的插入和查找都是O(1)时间复杂度

# 4. tuple
### 4.1 利用多维元组进行排序，避免重新定义类或结构体，并且利用其默认的比较大小顺序避免编写cmp


# 5. 数值表示
- `1e9`表示`10^9`，即10的9次方。
- `10e9`表示的是10的10次方

# 6. list
- `insert(i, x)` 在迭代器`i`之前插入`x`
- `j = erase(i)` 删除迭代器i指向的元素，并返回下一个元素
- 循环删除时，如果删除到begin()需要特别处理，因为通常写为`it!=lst.begin()`为循环条件。假设我们要删除闭区间 `[begin(), start]` 内的所有元素：
    ```cpp
    for(auto i=next(start); i!=lst.begin(); ) {
        lst.erase(prev(i));
    }
    ```
- 更一般的来说，从待删除元素的后一个元素开始迭代，删除其前一个元素x后，会将x前一个元素的指针维护并指向i，那么我们重复这个过程即可。
- 我们维护迭代器 `i` 时，使其永远指向正确插入位置的下一个位置。
- `prev()` 获取上一个迭代器
- `next()` 获取下一个迭代器