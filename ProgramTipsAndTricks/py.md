# 字符串

# 集合
```python
s1 = set([1, 2, 3])
s2 = set([3, 4, 5])
s3 = s1 & s2   # s1和s2求交集
s4 = s1 | s2   # s1和s2求并集
```

# Counter
```python
from collections import Counter

s1 = "123124"
s2 = "5435234242312"

c1 = Counter(list(s1))
c2 = Counter(list(s2))

c2.subtract(c2)

for k, v in c2.values:
    print(k, v)
```