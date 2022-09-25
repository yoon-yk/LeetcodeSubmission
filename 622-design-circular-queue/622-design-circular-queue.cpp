class MyCircularQueue {
private:
    list<int> mList;
    int k;
public:
    MyCircularQueue(int k) {
        this->k = k;
    }
    
    bool enQueue(int value) {
        if (mList.size() >= k) return false;
        mList.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if (mList.empty()) return false;
        mList.pop_front();
        return true;
    }
    
    int Front() {
        if (mList.empty()) return -1;
        return mList.front();
    }
    
    int Rear() {
        if (mList.empty()) return -1;
        return mList.back();
    }
    
    bool isEmpty() {
        return mList.empty();
    }
    
    bool isFull() {
        return mList.size() == k;
    }
};