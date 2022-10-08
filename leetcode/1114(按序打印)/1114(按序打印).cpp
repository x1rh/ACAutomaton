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