class HashTable {
public:
    unordered_map<int, int> m;
    int _capacity;
    HashTable(int capacity) {
        _capacity = capacity;
    }

    void insert(int key, int value) {
        m[key] = value;
        resize();
    }

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }
        return m[key];
    }

    bool remove(int key) {
        auto it = m.find(key);
        if (it != m.end()) {
            m.erase(key);
            _capacity--;
            return true;
        }
        return false;
    }

    int getSize() const {
        return m.size();
    }

    int getCapacity() const {
        return _capacity;
    }

    void resize() {
        if (m.size() >= _capacity/2) {
            _capacity *= 2;
        }
    }
};
