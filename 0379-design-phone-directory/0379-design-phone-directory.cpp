class PhoneDirectory {
public:
    // unordered set
    // taken
    unordered_set<int> taken;
    // not taken 
    unordered_set<int> notTaken;
    
    PhoneDirectory(int maxNumbers) {
        for (int i=0; i<maxNumbers; ++i) notTaken.insert(i);
    }
    
    int get() {
        if (notTaken.empty()) return -1;
        int rand = *notTaken.begin();
        taken.insert(rand);
        notTaken.erase(rand);
        return rand;
    }
    
    bool check(int number) {
        return (notTaken.count(number));
    }
    
    void release(int number) {
        taken.erase(number);
        notTaken.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */