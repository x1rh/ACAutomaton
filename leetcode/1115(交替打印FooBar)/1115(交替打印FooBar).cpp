class FooBar {
private:
    int n;
    std::mutex one, two;

public:
    FooBar(int n) {
        this->n = n;
        this->two.lock();

    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
        	this->one.lock();
        	printFoo();
            this->two.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
        	this->two.lock();
        	printBar();
            this->one.unlock();
        }
    }
};