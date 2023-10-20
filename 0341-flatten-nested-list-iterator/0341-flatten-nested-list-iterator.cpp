/**
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int idx;
    vector<int> v;
    void solve(vector<NestedInteger> &list) {
        for (NestedInteger & el : list) {
            if (el.isInteger())
                v.push_back(el.getInteger());
            else solve(el.getList());
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        solve(nestedList);
        idx = 0;
    }
    
    int next() {
        // Returns the next integer in the nested list.
        return v[idx++];
    }
    
    bool hasNext() {
        // Returns true if there are still some integers in the nested list 
        // and false otherwise.
        return (idx < v.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */