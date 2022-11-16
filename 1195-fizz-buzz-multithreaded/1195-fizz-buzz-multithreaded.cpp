class FizzBuzz {
private:
    int n;
    int curN;
    mutex m;
    bool done;
    condition_variable_any cv;

public:
    
    FizzBuzz(int n) {
        this->n = n;
        this->curN = 1;
        this->done = false;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {

        while (true) {
            lock_guard<mutex> lg(m);
            while (!((curN%3==0) && (curN%5!=0)) && !done) cv.wait(m);
            if (curN > n || done) {
                done = true;
                break;
            }
            printFizz();
            // cout << "FIZZ" << endl;
            curN++;
            cv.notify_all();
        }
        cv.notify_all();


    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        
        while (true){
            lock_guard<mutex> lg(m);
            while (!((curN%3!=0) && (curN%5==0)) && !done) cv.wait(m);
            if (curN > n || done) {
                done = true;
                break;
            }
            printBuzz();
            // cout << "BUZZ" << endl;
            curN++;
            cv.notify_all(); 
        }
        cv.notify_all();


    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            lock_guard<mutex> lg(m);
            while (!((curN%3==0) && (curN%5==0)) && !done) cv.wait(m);
            if (curN > n || done) {
                done = true;
                break;
            }
            printFizzBuzz();
            // cout << "FIZZBUZZ" << endl;
            curN++;
            cv.notify_all();            
        }
        cv.notify_all();

    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            lock_guard<mutex> lg(m);
            while (!((curN%3!=0) && (curN%5!=0)) && !done) cv.wait(m);
            if (curN > n || done) {
                done = true;
                break;
            }            
            printNumber(curN);
            // cout << curN << endl;
            curN++;
            cv.notify_all();
        }
        cv.notify_all();

    }
};