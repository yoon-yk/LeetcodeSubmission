class MedianFinder {
private:
    priority_queue<int> maxHeap; // left
    priority_queue<int, vector<int>, greater<int>> minHeap; // right
    
public:
    
    void addNum(int num) {
        
//         // 먼저 min heap 에 넣는걸 기본으로 함
        if (minHeap.size() > 0 && num > minHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }

        // 만약 개수가 1 이상 차이난다면, adjustment
        if (minHeap.size() > 1 + maxHeap.size()) { // minHeap 이 더 큰 경우
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if(maxHeap.size() > 1 + minHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }  
    }
    
    double findMedian() {
        double res = 0;
        if (minHeap.size() == 0) {
            res = maxHeap.top();
            return res;
        }
        if (minHeap.size() == maxHeap.size()) {
            double res = (minHeap.top() + maxHeap.top())/2.0;
            return res;
        }
        else if (minHeap.size() > maxHeap.size()) {
            res = minHeap.top();
            return res;
        } else {
            res = maxHeap.top();
            return res;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */