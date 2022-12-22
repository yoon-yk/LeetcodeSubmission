class Leaderboard {
public:
    unordered_map<int, int> board;
    multiset<pair<int, int>> ms;
    
    Leaderboard() {}
    
    void print() {
        for (auto & [score, player] : ms) {
            cout << score << "["<< player << "]" << " ";
        }
        cout << endl;
    }
    
    void addScore(int playerId, int score) {

        if (board.count(playerId)) {
            ms.erase(ms.find({board[playerId], playerId}));
            board[playerId] += score;
        } else {
            board[playerId] = score;
        }
        ms.insert({board[playerId], playerId});
    }
    
    int top(int K) {
        int cnt = K;
        int sum = 0;
        auto it = ms.rbegin();
        while (it != ms.rend() && cnt > 0) {
            sum += it->first;
            ++it, --cnt;
        }
        return sum;
    }
    
    void reset(int playerId) {

        if (board.count(playerId)) {
            ms.erase(ms.find({board[playerId], playerId}));
            board.erase(playerId);
        }

    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */