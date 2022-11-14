class Foo {
protected :
    int state = 0;
public:
    Foo() {
        state = 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state = 2;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while (state != 2) {
             std::this_thread::yield();
        }
        printSecond();
        state = 3;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while (state != 3) {
             std::this_thread::yield();
        }
        printThird();
    }
};