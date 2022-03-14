## 0、前言
sql虽然逻辑上完备，能够实现所有业务上的需求，但如果不是专家，真的用来写具体实现时，往往写出来的代码非常丑陋，这和sql比较晦涩，控制粒度太粗逃脱不了关系。此外，初学sql时感觉处处受限制，写起来很不爽。以下抽象一些常见场景，并提供实现的大致逻辑。

## 1、row_number()
row_number() over(partition by 分组列 order by 排序列 desc)


## 2、rank()


## 3、 dense_rank()


## 4、ntile


## 5、create function


## 6、求每个分组里的第一行数组


## 7、使用having子句 + group by求每个分组的行数
having 子句对每个分组进行操作，where是对每行进行操作

## 8、entity有x没有y
group by + having + count() + if()


参考： [1083-销售分析II](./1083-销售分析II.md)

## 9、entity在x里不在y里
用with语句分别求出在x里的和在y里的，然后做一次in操作

## 10、 去重：对某些字段的值相同的记录只保留一个
- distinct x1, x2, x3... 保留的是x1、x2、x3...组成的唯一元组
- 需要注意distinct (x1), x2, x3... 的效果和上面的是等价的

