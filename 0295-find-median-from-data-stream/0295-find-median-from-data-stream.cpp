class MedianFinder {
public:
    multiset<int> m;
    multiset<int>::iterator it;
    
    MedianFinder() {
        it = m.end();
    }
    
    // keep the pointer at the lower median
    
    /*  
       3 5 
         ^ 
    */
    void addNum(int num) {
        /*
        
        2 6 6 10
          ^
        */
        int n = m.size();
        m.insert(num);
        if (m.size() == 1) it = m.begin();
        else if (*it <= num) {
            if (n % 2 == 0) it++;
        } else {
            if (n % 2 == 1) it--;
        }
    }
    
    double findMedian() {
        if (m.size() % 2) // odd
           return *it;
        else return (*it + (*next(it))) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */