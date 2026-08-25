class LRUCache {
public:
    map<int, int>m;
    int _capacity;
    list<int> l;
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }

        auto it1 = find(l.begin(), l.end(), key);
        if (it1 != l.end()) {
            int t = *it1;
            l.push_back(t);
            l.erase(it1);
        }

        return m[key];
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            auto it1 = find(l.begin(), l.end(), key);
            if (it1 != l.end()) {
                int t = *it1;
                l.push_back(t);
                l.erase(it1);
            }
            m[key] = value;
            return;
        }

        if (m.size() >= _capacity) {
            int front = l.front();
            m.erase(front);
            l.pop_front();
        }
        m[key] = value;
        l.push_back(key);
    }
};
