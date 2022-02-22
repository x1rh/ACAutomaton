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