class MyCircularQueue {
private:
    vector<int> data;
    int head = 0;
    int tail = 0;
    int size = 0;
    int cap = 0;
    
public:
    MyCircularQueue(int k) {
        data.resize(k);
        cap = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        
        tail = (tail + 1) % cap;
        if (size == 0) head = tail;
        size++;
        data[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        
        size--;
        head = (head + 1) % cap;
        
        return true;
    }
    
    int Front() {
        return (isEmpty() ? -1 : data[head]);
    }
    
    int Rear() {
        return (isEmpty() ? -1 : data[tail]);
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == data.size();
    }
};