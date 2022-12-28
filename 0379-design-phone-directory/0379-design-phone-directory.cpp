class PhoneDirectory {
public:
    // unordered set
    // taken
    unordered_set<int> taken;
    // not taken 
    deque<int> available;
    void print() {
        cout << "**********" << endl;
        cout << "available" << endl;
        for (auto i : available) cout << i << " ";
        cout << endl;
        cout << "taken" << endl;
        for (auto i : taken) cout << i << " ";
        cout << endl;
        cout << "**********" << endl;
    }
    
    PhoneDirectory(int maxNumbers) {
        for (int i=0; i<maxNumbers; ++i) available.push_back(i);
        // print();
    }
    
    int get() {
        // cout << "Get" << endl;

        if (available.empty()) return -1;
        int rand = available.front(); available.pop_front();
        taken.insert(rand);
        // print();
        return rand;
    }
    
    bool check(int number) {
        // cout << "Check" << endl;
        // print();
        return (!taken.count(number));
    }
    
    void release(int number) {
        if (!taken.count(number)) return;
        taken.erase(number);
        available.push_back(number);
        // cout << "Release" << endl;
        // print();
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */