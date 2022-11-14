class Foo {
protected :
    mutex m;
    condition_variable_any cv;
    int state = 0;
public:
    Foo() {
        state = 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        lock_guard<mutex> lg(m);
        printFirst();
        state = 2;
        if (state == 2) cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        lock_guard<mutex> lg(m);
        while (state < 2) cv.wait(m);
        printSecond();
        state = 3;
        if (state == 3) cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        lock_guard<mutex> lg(m);
        while (state < 3) cv.wait(m);
        printThird();
    }
};