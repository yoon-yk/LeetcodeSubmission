class MedianFinder {
public:
    
    priority_queue<int> maxHeap; // first half (n/2 ~ n/2+1)
    priority_queue<int, vector<int>, greater<int>> minHeap; // second half (n/2)
    
    MedianFinder() {}
    
    void addNum(int num) {
        
        if (!minHeap.empty() && num > minHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        
        if (minHeap.size() + 1 < maxHeap.size()) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();

        }
        else if (maxHeap.size() < minHeap.size()) {
            return minHeap.top();
        }
        else {
            return (((double)maxHeap.top() + (double)minHeap.top()) / 2.0 );
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */