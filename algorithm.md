## 算法

### 前缀和
注意按照定义: $pre[i]=\sum_{j=0}^{i-1}{arr[j]}$
即pre[i]表示前i-1个数的和

### 贪心
贪心没什么好说的


### 二分法
```c++

```

### 三分

### 尺取

### dp
- 01背包
- 多重背包
- 最大连续子串和

### 快速幂/矩阵快速幂

### 大数加法

### 大数减法

### 大数乘法

### 大数除法

### 链表合并

### 多项式加法运算(链表)

### 多项式乘法(链表)

### 括号匹配

### 后缀表达式

### 树的高度

### 树的直径

### 树的重心

### 给出前序遍历和中序遍历构造二叉树

### 给出后序遍历和中序遍历构造二叉树

### 哈夫曼树

### 树的左右互换

### 最近公共祖先

### k限度最小生成树


### 堆(建堆，插入，删除)

### bfs

### dfs

### 回溯

### union-set

### dijkstra && 堆优化dijkstra

### floyd

### prim

### kruskal

### 拓扑排序

### 排序(全部实现一遍)

### 逆序数

### KMP

### 进制转换

### 时间问题
#### 计算某一天是星期几(leetcode1185)
```c++
bool judge(int year){
    return (year%4==0&&year%100!=0) || year%400==0;
}

string dayOfTheWeek(int day, int month, int year) {
    vector<string> v({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"});
    vector<int> mm({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
    int y = 1970;
    int m = 1;
    int d = 1;
    int now = 4;

    int delta = 0;
    for(int i=y; i<year; ++i){
        if(judge(i)){
            delta += 366;
        }
        else{
            delta += 365;
        }
    }

    for(int i=1; i<month; ++i){
        delta += mm[i-1];
    }
    delta += day;
    if(judge(year) && month>2) ++delta;
    return v[(now + delta - 1)%7];
}
```

蔡勒（Zeller）公式，是一个计算星期的公式，随便给一个日期，就能用这个公式推算出是星期几。(注意对应0对应sunday)

$w=([\frac{c}{4}]-2c+y+[\frac{y}{4}]+[\frac{13\times(m+1)}{5}]+d-1)MOD7$
$w=(w+7)MOD7$

```c++
string dayOfTheWeek(int day, int month, int year) {
        vector<string> v({"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"});
        if(month<3){
            --year;
            month += 12;
        }
        int c = year / 100;
        int y = year - c*100;
        int w = (c/4-2*c+y+y/4+13*(month+1)/5+day-1)%7;
        cout<<w<<endl;
        return v[(w+7)%7];
    }
```

#### 计算两天之间的时间间隔
#### 判断闰年
```c++
bool judge(int year){
    return (year%4==0&&year%100!=0) || year%400==0;
}
```


### RMQ

### 质数筛法

### gcd

### lucas算法求C(n, m) % p

### 康托展开(全排列字典序)

### 凸包扫描

### 最近点对

### 扫描线
