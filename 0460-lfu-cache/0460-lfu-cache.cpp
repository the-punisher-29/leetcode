class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq; // key -> {value, frequency}
    unordered_map<int, list<int>> freqToKeys; // frequency -> list of keys with this frequency
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in the list

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        // If key doesn't exist, return -1
        if (keyToValFreq.find(key) == keyToValFreq.end()) {
            return -1;
        }
        
        // Increase frequency and update position
        updateFrequency(key);
        
        // Return the value
        return keyToValFreq[key].first;
    }
    
    void put(int key, int value) {
        // Edge case: capacity is 0
        if (capacity == 0) {
            return;
        }
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value; // Update value
            updateFrequency(key); // Update frequency
            return;
        }
        if (keyToValFreq.size() >= capacity) {
            evict();
        }
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_back(key);
        keyToIter[key] = --freqToKeys[1].end();
        minFreq = 1; // New key has the minimum frequency
    }
    
private:
    void updateFrequency(int key) {
        int oldFreq = keyToValFreq[key].second;
        int newFreq = oldFreq + 1;
        keyToValFreq[key].second = newFreq;
        freqToKeys[oldFreq].erase(keyToIter[key]);
        if (freqToKeys[oldFreq].empty() && oldFreq == minFreq) {
            minFreq++;
            freqToKeys.erase(oldFreq);
        }
        freqToKeys[newFreq].push_back(key);
        keyToIter[key] = --freqToKeys[newFreq].end();
    }
    
    void evict() {
        // Get the least recently used key from the minimum frequency list
        int keyToRemove = freqToKeys[minFreq].front();
        freqToKeys[minFreq].pop_front();
        keyToValFreq.erase(keyToRemove);
        keyToIter.erase(keyToRemove);
        // If the frequency list is now empty, we can remove it
        // (minFreq will be updated on the next insertion)
        if (freqToKeys[minFreq].empty()) {
            freqToKeys.erase(minFreq);
        }
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */