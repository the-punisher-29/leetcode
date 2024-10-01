//combo of hashmap and dll
class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node *prev, *next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    unordered_map<string, Node*> keyMap;
    Node *head, *tail;

    void insertNode(Node *node, Node *newNode) {
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(INT_MAX);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if (keyMap.find(key) == keyMap.end()) {
            if (head->next->count != 1) {
                insertNode(head, new Node(1));
            }
            head->next->keys.insert(key);
            keyMap[key] = head->next;
        } else {
            Node *node = keyMap[key];
            Node *nextNode = node->next;
            if (nextNode->count != node->count + 1) {
                insertNode(node, new Node(node->count + 1));
            }
            nextNode = node->next;
            nextNode->keys.insert(key);
            keyMap[key] = nextNode;
            node->keys.erase(key);
            if (node->keys.empty()) {
                removeNode(node);
            }
        }
    }
    
    void dec(string key) {
        Node *node = keyMap[key];
        if (node->count == 1) {
            keyMap.erase(key);
        } else {
            Node *prevNode = node->prev;
            if (prevNode->count != node->count - 1) {
                insertNode(prevNode, new Node(node->count - 1));
            }
            prevNode = node->prev;
            prevNode->keys.insert(key);
            keyMap[key] = prevNode;
        }
        node->keys.erase(key);
        if (node->keys.empty()) {
            removeNode(node);
        }
    }
    
    string getMaxKey() {
        return tail->prev == head ? "" : *(tail->prev->keys.begin());
    }
    
    string getMinKey() {
        return head->next == tail ? "" : *(head->next->keys.begin());
    }
};
/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */