# 题目
`https://leetcode-cn.com/problems/print-in-order/`

# 思路
设置两个互斥锁one和two：
1. Foo类初始化时，先获取这两个锁，表明第一个打印函数拥有这两个
2. 第一个打印函数结束后，释放第一个锁，第二个打印函数得以执行，然后释放第二个锁
3. 第三个打印函数获得锁后，得以执行。

```python
from threading import Lock

class Foo(object):
    def __init__(self):
        self.one = Lock()
        self.two = Lock()
        self.one.acquire()
        self.two.acquire()


    def first(self, printFirst):
        printFirst()
        self.one.release()


    def second(self, printSecond):
        with self.one:
            printSecond()
            self.two.release()
            
            
    def third(self, printThird):
        with self.two:
            printThird()
```


```cpp
class Foo {
public:
    mutex one, two;
    Foo() {
        one.lock();
        two.lock();
    }

    void first(function<void()> printFirst) {
        printFirst();
        one.unlock();
    }

    void second(function<void()> printSecond) {
        this->one.lock();
        printSecond();
        this->two.unlock();
    }

    void third(function<void()> printThird) {
        this->two.lock();
        printThird();
    }
};
```


官方题解：
```cpp
#include <semaphore.h>

class Foo {

protected:
    sem_t firstJobDone;
    sem_t secondJobDone;

public:

    Foo() {
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first".
        printFirst();
        sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstJobDone);
        // printSecond() outputs "second".
        printSecond();
        sem_post(&secondJobDone);
        
    }

    void third(function<void()> printThird) {
        sem_wait(&secondJobDone);
        // printThird() outputs "third".
        printThird();
    }
};

```