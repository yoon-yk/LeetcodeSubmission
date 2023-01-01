class Solution {
public:
    bool canChange(string start, string target) {
        int sid = 0, tid = 0;
        while (sid < start.size() || tid < target.size()) {
            while (sid < start.size() && start[sid] == '_') ++sid;
            while (tid < target.size() && target[tid] == '_') ++tid;
            if ((sid == start.size() || tid == target.size()) ||
                (start[sid] != target[tid]) || 
                (start[sid] == 'L' && sid < tid) || 
                (start[sid] == 'R' && sid > tid)) break;
            ++sid, ++tid;
        }
        return (sid == start.size() && tid == target.size());
    }
};