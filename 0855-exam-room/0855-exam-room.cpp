class ExamRoom {
public:
    int size;
    set<int> taken;
    
    ExamRoom(int n) {
        size = n;
    }
    
    int seat() {
        if (taken.empty()) {
            taken.insert(0);
            return 0;
        }
        
        int distWhenPlaceZero = *taken.begin();
        int ans = 0;
        int maxDist = distWhenPlaceZero;
        
        int curDist, midId;
        for (auto it = next(taken.begin()); it != taken.end(); ++it) {
            curDist = ((*it)-(*prev(it))) >> 1;
            midId = (*prev(it)) + curDist;
            
            if (curDist > maxDist) {
                maxDist = curDist;
                ans = midId;
            }
        }
        
        int distWhenPlaceMaxi = (size-1)-(*taken.rbegin());
        if (maxDist < distWhenPlaceMaxi) {
            ans = size-1;
            maxDist = distWhenPlaceMaxi;
        }

        taken.insert(ans);
        return ans;
    }

    
    void leave(int p) {
        taken.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */