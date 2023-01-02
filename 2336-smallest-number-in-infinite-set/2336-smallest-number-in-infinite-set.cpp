class SmallestInfiniteSet {
public:
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    multiset<int> ms;
    
    SmallestInfiniteSet() {
        ms.insert(1);
    }
    
    int popSmallest() {
        int ret = *ms.begin();
        if (ms.size() == 1) 
            ms.insert(*ms.begin()+1);
        ms.erase(ms.begin());

        return ret;
    }
    
    void addBack(int num) {
        if (num < *ms.rbegin() && ms.find(num) == ms.end()) {
            ms.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */