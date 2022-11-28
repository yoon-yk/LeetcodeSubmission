class RandomizedCollection {
public:
  vector<int> v;
  unordered_map<int, unordered_set<int>> m;

  bool insert(int val) {
    v.push_back(val);
    m[val].insert(v.size() - 1);
    return m[val].size() == 1;
  }
        
  bool remove(int val) {
    auto it = m.find(val);
    if (it != end(m)) {
      auto free_pos = *it->second.begin(); // 삭제할 원소의 인덱스
      it->second.erase(it->second.begin()); // 위에서 찾은 인덱스 삭제
      v[free_pos] = v.back(); // 삭제할 원소가 위치한 자리에 맨 뒷 원소 넣기
      m[v.back()].insert(free_pos); // 새로 바뀐 인덱스 넣기
      m[v.back()].erase(v.size() - 1); // 맨 뒤 원소의 인덱스 셋에서 인덱스 삭제
      v.pop_back(); // arr자체에서 맨 뒤 원소 지우기
      if (it->second.size() == 0) m.erase(it); // 만약에 지운 인덱스가 해쉬셋의 유일한 원소였다면 m에서 해당 엔트리 지우기 
      return true;
    }
    return false;
  }
  int getRandom() { return v[rand() % v.size()]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */