# 题目
`https://leetcode-cn.com/problems/print-zero-even-odd/`

# 思路
- 注意锁的lock和unlock顺序
- 注意循环次数
- 注意循环

```cpp
class ZeroEvenOdd {
private:
    int n, i;
    mutex one, two, thr;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i = 1;
        two.lock();
        thr.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0; i<this->n; ++i){
            one.lock();
            printNumber(0);
            if((this->i) & 1){
                thr.unlock();
            }
            else{
                two.unlock();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        int m = this->n / 2;

        for(int i=0; i<m; ++i){
            two.lock();
            printNumber(this->i);
            this->i += 1;
            one.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        int m = 0;
        if(this->n & 1){
            m = 1 + this->n / 2;
        }
        else{
            m = this->n / 2;
        }

        for(int i=0; i<m; ++i){
            thr.lock();
            printNumber(this->i);
            this->i += 1;
            one.unlock();
        }
    }
};
```