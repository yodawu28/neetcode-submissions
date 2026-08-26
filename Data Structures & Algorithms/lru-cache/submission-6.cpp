class LRUCache {
public:
    unordered_map<int, int>m;
    unordered_map<int, list<int>::iterator> positions;
    int _capacity;
    list<int> state;
    
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        
        if (it == m.end()) {
            return -1;
        }
        
        state.erase(positions[key]);
        state.push_back(key);
        positions[key] = prev(state.end());
        
        return m[key];
    }
    
    void put(int key, int value) {
        auto itFind = m.find(key);
        if (itFind != m.end()) {
            state.erase(positions[key]);
            state.push_back(key);
            positions[key] = prev(state.end());
            m[key] = value;
        } else {
            if (m.size() >= _capacity) {
                int top = state.front();
                positions.erase(top);
                state.pop_front();
                m.erase(top);
            }
            
            auto it = positions.find(key);
            if (!state.empty() && it != positions.end()) {
                state.erase(positions[key]);
            }
            state.push_back(key);
            positions[key] = prev(state.end());
            m[key] = value;
        }
    }
};
