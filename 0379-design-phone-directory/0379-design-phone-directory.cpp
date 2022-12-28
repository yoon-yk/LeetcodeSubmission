class PhoneDirectory {
public:
    // unordered set
    // taken
    unordered_set<int> taken;
    // not taken 
    deque<int> available;

    PhoneDirectory(int maxNumbers) {
        for (int i=0; i<maxNumbers; ++i) available.push_back(i);
    }
    
    int get() {
        if (available.empty()) return -1;
        int rand = available.front(); available.pop_front();
        taken.insert(rand);
        return rand;
    }
    
    bool check(int number) {
        return (!taken.count(number));
    }
    
    void release(int number) {
        if (!taken.count(number)) return;
        taken.erase(number);
        available.push_back(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */