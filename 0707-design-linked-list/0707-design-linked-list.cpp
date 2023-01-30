class Node {
public:
    int val;
    Node* next;
    Node* prev;
    
    Node(int _val) {
        val = _val;
        next = prev = NULL;
    }
}; 
class MyLinkedList {
public:
    int size;
    Node* head;
    Node* tail;
    MyLinkedList() {
        size = 0;
        head = new Node(-1);
        tail = new Node(-1);
        head->prev = tail->next = NULL;
        head->next = tail;
        tail->prev = head;
    }
    
    Node* getNodeBeforeKth(int idx) {
        if (idx > size) return NULL;
        if (idx < (size >> 1)) 
            return getNodeBeforeKthFromHead(idx);
        return getNodeBeforeKthFromTail(idx);
    }
    
    Node* getNodeBeforeKthFromTail(int index) {
        Node* ptr = tail;
        index = size-index+1;
        while (ptr && index--) 
            ptr = ptr->prev;
        if (!ptr) return NULL;
        return ptr;
    }
    
    Node* getNodeBeforeKthFromHead(int index) {
        Node* ptr = head;
        while (ptr && index--) 
            ptr = ptr->next;
        if (!ptr || !ptr->next) return NULL;
        return ptr;
    }
    
    int get(int index) {
        Node* ptr = getNodeBeforeKth(index);
        if (ptr == NULL || ptr->next == tail) return -1;
        return ptr->next->val;
    }
    
    void addAtHead(int val) {
        addNewNode(val, head, head->next);
        print();
    }
    
    void addAtTail(int val) {
        addNewNode(val, tail->prev, tail);
        print();
    }
    
    void print() {
        // Node* ptr = head;
        // while (ptr) {
        //     cout << ptr->val << " ";
        //     ptr = ptr->next;
        // }cout << endl;
    }
    
    void addNewNode(int val, Node* prevNode, Node* nextNode) {
        Node* newNode = new Node(val);
        newNode->next = nextNode;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        nextNode->prev = newNode;
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        Node* prevNode = getNodeBeforeKth(index);
        if (!prevNode) return;
        addNewNode(val, prevNode, prevNode->next);
        print();
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        Node* prevNode = getNodeBeforeKth(index);
        if (!prevNode) return;
        Node* nextNode = prevNode->next->next;
        delete prevNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        print();
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */