class MedianFinder {
public:
    priority_queue<int> lower; 
    priority_queue<int, vector<int>, greater<int>> upper; 
    int totalSize;
    
    MedianFinder() {
        totalSize = 0;
    }
    
    /*
    
    1 3 4 | 5 6 7
    
    */
    void addNum(int num) {
        if (totalSize == 0) lower.push(num);
        else {
            if (!lower.empty() && num < lower.top()) {
                lower.push(num);
                if (lower.size() > upper.size() + 1) {
                    upper.push(lower.top());
                    lower.pop();
                }
            } else {
                upper.push(num);
                if (upper.size() > lower.size()) {
                    lower.push(upper.top());
                    upper.pop();
                }
            }
        }
        totalSize++;

    }
    
    double findMedian() {
        if (totalSize == 0) return 0;
        if (totalSize % 2)  // odd
            return lower.top();
        return (lower.top() + upper.top()) * 0.5;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */