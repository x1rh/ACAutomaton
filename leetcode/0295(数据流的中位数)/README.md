# 题目
`https://leetcode-cn.com/problems/find-median-from-data-stream/`


# 思路
现在假设将所有输入的数字排序，将小于等于中位数的部分记为l，大于中位数的部分叫r。

现在利用一个大顶堆mx用来维护l，用一个小顶堆维护r。  
- 初始化时：当mx为空时，将num放入mx  
- 对于一个新来的num
  - 如果它比mx.top()小，则放入mx，同时我们可能需要维护mn，将mx.top()放入mn后，mx.pop()
  - 如果它比mx.top()大，则放入mn，同时我们可能需要维护mx，将mn.top()放入mx后，mn.pop()

注意我用来可能来描述。考虑1,1,2这种情况，两个1应该放在mx，而2放在mn。


`if (mn.size() + 1 < mx.size())`和`if (mn.size() > mx.size())`的区别在于，mx可能比mn多存放了一个中位数
```cpp
class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> mx;
    priority_queue<int, vector<int>, greater<int>> mn;

    MedianFinder() {}

    void addNum(int num) {
        if (mx.empty() || num <= mx.top()) {
            mx.push(num);
            if (mn.size() + 1 < mx.size()) {   
                mn.push(mx.top());
                mx.pop();
            }
        } else {
            mn.push(num);
            if (mn.size() > mx.size()) {
                mx.push(mn.top());
                mn.pop();
            }
        }
    }

    double findMedian() {
        if (mx.size() > mn.size()) {
            return mx.top();
        }
        return (mx.top() + mn.top()) / 2.0;
    }
};

```
