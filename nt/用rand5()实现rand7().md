# 用rand5()实现rand7()

## rand7()可以实现rand5()
实现方法如下：
```cpp
int rand5(){
    int x = rand7();
    while(x>5){
        x = rand7();
    }
    return x;
}

```
若rand7()获得了闭区间[1, 5]内任意一个数则直接返回，否则多次调用rand7()，直到产生闭区间[1, 5]内的数为止。

简单证明如下：
设P{X=1}为rand5()生成随机数1的概率，cnt为调用rand7()次数，已知rand7()返回一个数的概率是1/7,则将P{X=1}进行全集分解：
```
  P{X=1} 
= P{X=1, cnt=1} + P{X=1, cnt=2} + .... + P{X=1, cnt=infinity} 
= 1/7 + (1-5/7)^1 * (1/7) + ... + (1-5/7)^infinity * (1/7)
= 1/5 
```


## 推论
任意randa，randb，当a>b时，可以由randa()实现randb()



## 用rand5()实现rand7()
利用推论实现用rand5()实现rand7()：

第一步先实现一个randX()， X>5:  
使用多个rand5()组合的方法，randX = 5 * (rand5()-1) + rand5()，其中X=25

注意，必须保证randX的每个数产生的概率是等同的，我们稍加思考，便可论证上面的组合产生的数是唯一的：  
子式（1）： 5 * (rand5()-1)    产生0, 5, 10, 15, 20    
子式（2）： rand5()            产生1， 2， 3， 4， 5  
合并在一起产生区间[0, 25]内的任意一个数y，且y的由子式（1）（2）表达唯一，从而保证每个数产生的概率相同

```
int rand25(){
    return 5 * (rand5()-1);
}


int rand7(){
    int x = 8;
    while(x>7){
        x = rand25()
    }
    return x;
}
```




## 一般化
用randa()实现randb()，先构造randa^2() = a * (randa()-1) + randa()


给你randa()和randb()生成randab():
```
randab = b * (randa() - 1) + randb;
randab = a * (randb() - 1) + randa;
```


## 思考
可以取模加速吗？
我觉得不可以


