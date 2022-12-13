class MedianFinder {
public:
    priority_queue<int> lower; 
    priority_queue<int, vector<int>, greater<int>> upper; 
    int totalSize;
    
    MedianFinder() {
        totalSize = 0;
    }

    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top());
        lower.pop();

        if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
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